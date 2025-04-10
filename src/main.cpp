#include "Core/LibraryLoader.hpp"
#include "Core/Exceptions.hpp"
#include "Shared/IDisplay.hpp"
#include <iostream>
#include <filesystem>
#include <functional>
#include <vector>
#include <string>

using namespace Arcade;

static void usage(const std::string &name) {
    std::cerr << "Usage: " << name << " <path_to_display_library>" << std::endl;
}

bool isGraphicalLibrary(const std::string &path) {
    try {
        Core::LibraryLoader loader;
        loader.loadLibrary(path);

        auto createDisplayFunc = loader.getSymbol("createDisplay");
        return createDisplayFunc != nullptr;
    } catch (const Core::Exceptions::Exception &e) {
        return false;
    }
}

std::vector<std::string> findLibraries(const std::string &directory,
                                       const std::function<bool(const std::string&)> &validator) {
    std::vector<std::string> result;

    if (!std::filesystem::exists(directory) || !std::filesystem::is_directory(directory))
        return result;

    for (const auto &entry : std::filesystem::directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().extension() == ".so") {
            std::string path = entry.path().string();
            if (validator(path)) {
                result.push_back(path);
            }
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage(argv[0]);
        return 84;
    }

    std::string libraryPath = argv[1];

    if (!std::filesystem::exists(libraryPath)) {
        std::cerr << "Error: '" << libraryPath << "' does not exist" << std::endl;
        return 84;
    }
    if (!isGraphicalLibrary(libraryPath)) {
        std::cerr << "Error: '" << libraryPath << "' not a graphical library" << std::endl;
        return 84;
    }

    try {
        Core::LibraryLoader libraryLoader;
        libraryLoader.loadLibrary(libraryPath);

        using CreateDisplayFunc = Shared::IDisplay *(*)();
        auto createDisplayFunc = reinterpret_cast<CreateDisplayFunc>(
            libraryLoader.getSymbol("createDisplay"));

        std::unique_ptr<Shared::IDisplay> display(createDisplayFunc());

        auto graphicalLibs = findLibraries("./lib", isGraphicalLibrary);

        // TODO: Check si c'est une biblio de jeux

        // TODO: Ajouter le jeu du menu et la boucle principale

    } catch (const Core::Exceptions::Exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 84;
    }

    return 0;
}
#include <bits/stdc++.h>

struct File {
    std::string name;
    File(const std::string &name) : name(name) {}; 
};

struct Directory {
    std::vector<File *> files;
    std::vector<Directory *> directories;
    std::string name;
    Directory *parent{nullptr};

    Directory(const std::string &name, Directory *parent = nullptr) : name(name), parent(parent) {};

    ~Directory() {
        for (auto file : files) {
            delete file;
        }

        for (auto directory : directories) {
            delete directory;
        }
    }

    bool check_duplicate_name(const std::string &path) {
        for (auto &file : files) {
            if (file->name == path) {
                return true;
            }
        }

        for (auto &directory : directories) {
            if (directory->name == path) {
                return true;
            }
        }

        return false;
    }

    void create_folder(const std::string &path) {
        if (!check_duplicate_name(path)){
            directories.push_back(new Directory(path, this));
        }
    }

    void create_file(const std::string &path) {
        if (!check_duplicate_name(path)){
            files.push_back(new File(path));
        }
    }

    void set_parent(Directory *parent_directory) {
       parent = parent_directory;
    }

    std::string dir() {
        std::vector<std::string> all;
        std::string res = "";

        for (auto &directory : directories) {
            all.push_back(directory->name);
        }

        for (auto &file : files) {
            all.push_back(file->name);
        }

        std::sort(all.begin(), all.end());
        for (auto &str : all) {
            res = res + str + "  ";
        }

        if (res.size() >= 2) {
            res.pop_back();   // remove last space
            res.pop_back();   // remove last space
        }

        return res;
    }

    std::string pwd_helper() {
        std::string res = name;
        if (parent) {
            std::string parent_path = parent->pwd_helper();
            if (parent_path.back() != '/') {
                parent_path += "/";
            }
            res = parent_path + res;
        }

        return res;
    }

    std::string pwd() {
        std::string res = pwd_helper();
        return res;
    }

    std::optional<Directory *> find_directory(const std::string &path) {
        if (path == ".") {
            return this;
        }

        if (path == "..") {
            if (parent) {
                return parent;
            }
            return this;
        }

        if (path == "../..") {
            if (parent && parent->parent) {
                return parent->parent;
            } else if (parent) {
                return parent;
            } 
            return this;
        }

        for (auto directory : directories) {
            if (directory->name == path) {
                return directory;
            }
        }

        return std::nullopt;
    }

    std::optional<File *> find_file(const std::string &path) {
        for (auto &file : files) {
            if (file->name == path) {
                return file;
            }
        }
        return std::nullopt;
    }

    void remove_file(const std::string &path) {
        files.erase(std::remove_if(files.begin(), files.end(), [&path](File *current_file) {
                return current_file->name == path;
        }), files.end());
    }

    void remove_folder(const std::string &path) {
        directories.erase(std::remove_if(directories.begin(), directories.end(), [&path](Directory *current_folder) {
                return current_folder->name == path;
        }), directories.end());
    }
};

int main() {

    int n;
    std::cin >> n;

    Directory *const root = new Directory{"/"};
    Directory *cwd = root;

    for (int i = 0; i < n; ++i) {
        std::string cmd;
        std::cin >> cmd;

        if (cmd == "mkdir") {
            std::string name; 
            std::cin >> name;
            cwd->create_folder(name);
        } else if (cmd == "touch") {
            std::string name;
            std::cin >> name;
            cwd->create_file(name);
        } else if (cmd == "cd") {
            std::string name;
            std::cin >> name;
            auto directory = cwd->find_directory(name);
            if (directory) {
                cwd = directory.value();
            }
        } else if (cmd == "rmdir") {
            std::string name;
            std::cin >> name;    
            cwd->remove_folder(name);        
        } else if (cmd == "rm") {
            std::string name;
            std::cin >> name;
            cwd->remove_file(name);
        } else if (cmd == "pwd") {
            std::string path = cwd->pwd();
            std::cout << path << "\n";
        } else if (cmd == "dir") {
            std::string output = cwd->dir();
            if (output.size()) {
                std::cout << cwd->dir() << "\n";
            }
        }
    }

    delete root;

    return 0;
}

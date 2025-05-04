#ifndef W1LTOFF_WTOOLS_FILE_HPP
#define W1LTOFF_WTOOLS_FILE_HPP

#include <filesystem>
#include <optional>

class WtFile {
  public:
    std::filesystem::path m_sFilePath;
    std::optional<std::string> m_ostrFileContent;

    WtFile(const char *pFilePath);

    // void open();
    // void close();

    void write(const char *pContent);
    void writeln(const char *pContent);
    void append(const char *pContent);
    void appendln(const char *pContent);
    void clear();
    std::string read(bool bForceRead = false);

    void create();

  private:
    // std::fstream m_sFile;
    bool m_bIsOpen;
    bool isFileExists();
};

#endif // W1LTOFF_WTOOLS_FILE_HPP
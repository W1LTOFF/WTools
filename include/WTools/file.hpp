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
    static void write(const char *pContent, const char *pFilePath);

    void writeln(const char *pContent);
    static void writeln(const char *pContent, const char *pFilePath);

    void append(const char *pContent);
    static void append(const char *pContent, const char *pFilePath);

    void appendln(const char *pContent);
    static void appendln(const char *pContent, const char *pFilePath);

    void clear();
    static void clear(const char *pFilePath);

    std::string read(bool bForceRead = false);
    static std::string read(const char *pFilePath);

    void create();

  private:
    // std::fstream m_sFile;
    bool m_bIsOpen;
    bool isFileExists();
};

#endif // W1LTOFF_WTOOLS_FILE_HPP
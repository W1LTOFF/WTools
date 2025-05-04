#ifndef W1LTOFF_WTOOLS_FILE_HPP
#define W1LTOFF_WTOOLS_FILE_HPP

#include <filesystem>
#include <fstream>
#include <optional>

class WtFile {
  public:
    std::filesystem::path m_sFilePath;
    std::optional<std::string> m_ostrFileContent;

    WtFile(const char *pFilePath);

    void open();
    void close();

    void write(const char *pContent);
    void append(const char *pContent);
    std::string read(bool bForceRead = false);

  private:
    std::fstream m_sFile;
    bool m_bIsOpen;
    bool isFileExists();
};

#endif // W1LTOFF_WTOOLS_FILE_HPP
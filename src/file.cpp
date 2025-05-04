#include "WTools/file.hpp"
#include <optional>
#include <print>

WtFile::WtFile(const char *pFilePath) {
    m_sFilePath = pFilePath;

    open();
}

bool WtFile::isFileExists() {
    return std::filesystem::exists(m_sFilePath);
}

std::string WtFile::read(bool bForceRead) {
    if (!m_ostrFileContent.has_value() || bForceRead) {
        std::stringstream strBuffer;
        strBuffer << m_sFile.rdbuf();
        m_ostrFileContent = strBuffer.str();
    }

    return m_ostrFileContent.value();
}

void WtFile::write(const char *pContent) {
    m_sFile << pContent;
    m_sFile.seekg(0);
}

void WtFile::open() {
    m_sFile = std::fstream(m_sFilePath, std::ios::in | std::ios::out | std::ios::trunc);

    m_bIsOpen = true;
}
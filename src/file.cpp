#include "WTools/file.hpp"
#include <format>
#include <fstream>
#include <ios>
#include <optional>
#include <print>

WtFile::WtFile(const char *pFilePath) {
    m_sFilePath = pFilePath;

    if (!isFileExists()) {
        std::ofstream sFileR(m_sFilePath);
    }

    // open();
}

bool WtFile::isFileExists() {
    return std::filesystem::exists(m_sFilePath);
}

std::string WtFile::read(bool bForceRead) {
    if (!m_ostrFileContent.has_value() || bForceRead) {
        std::stringstream strBuffer;
        std::ifstream sFileR(m_sFilePath, std::ios::in);
        strBuffer << sFileR.rdbuf();
        m_ostrFileContent = strBuffer.str();
    }

    return m_ostrFileContent.value();
}

void WtFile::write(const char *pContent) {
    std::ofstream sFileWT(m_sFilePath, std::ios::trunc);
    m_ostrFileContent = pContent;
    sFileWT << pContent;
}
void WtFile::writeln(const char *pContent) {
    write(std::format("{}\n", pContent).c_str());
}

void WtFile::append(const char *pContent) {
    std::ofstream sFileWA(m_sFilePath, std::ios::app);
    m_ostrFileContent = std::format("{}{}", m_ostrFileContent.has_value() ? m_ostrFileContent.value() : "", pContent);
    sFileWA << pContent;
}
void WtFile::appendln(const char *pContent) {
    append(std::format("{}\n", pContent).c_str());
}

void WtFile::clear() {
    write("");
}

// void WtFile::open() {
//     m_sFile = std::fstream(m_sFilePath, std::ios::in | std::ios::out | std::ios::trunc);

//     m_bIsOpen = true;
// }
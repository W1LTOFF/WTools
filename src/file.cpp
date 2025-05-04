#include "WTools/file.hpp"
#include <format>
#include <fstream>
#include <ios>
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

// ? static
std::string WtFile::read(const char *pFilePath) {
    std::stringstream strBuffer;
    std::ifstream sFileR(pFilePath, std::ios::in);
    strBuffer << sFileR.rdbuf();
    return strBuffer.str();
}

void WtFile::write(const char *pContent) {
    std::ofstream sFileWT(m_sFilePath, std::ios::trunc);
    m_ostrFileContent = pContent;
    sFileWT << pContent;
}

// ? static
void WtFile::write(const char *pContent, const char *pFilePath) {
    std::ofstream sFileWT(pFilePath, std::ios::trunc);
    sFileWT << pContent;
}

void WtFile::writeln(const char *pContent) {
    write(std::format("{}\n", pContent).c_str());
}

// ? static
void WtFile::writeln(const char *pContent, const char *pFilePath) {
    WtFile::write(std::format("{}\n", pContent).c_str(), pFilePath);
}

void WtFile::append(const char *pContent) {
    std::ofstream sFileWA(m_sFilePath, std::ios::app);
    m_ostrFileContent = std::format("{}{}", m_ostrFileContent.has_value() ? m_ostrFileContent.value() : "", pContent);
    sFileWA << pContent;
}

// ? static
void WtFile::append(const char *pContent, const char *pFilePath) {
    std::ofstream sFileWA(pFilePath, std::ios::app);
    sFileWA << pContent;
}

void WtFile::appendln(const char *pContent) {
    append(std::format("{}\n", pContent).c_str());
}

// ? static
void WtFile::appendln(const char *pContent, const char *pFilePath) {
    WtFile::append(std::format("{}\n", pContent).c_str(), pFilePath);
}

void WtFile::clear() {
    write("");
}

// ? static
void WtFile::clear(const char *pFilePath) {
    write("", pFilePath);
}

// void WtFile::open() {
//     m_sFile = std::fstream(m_sFilePath, std::ios::in | std::ios::out | std::ios::trunc);

//     m_bIsOpen = true;
// }
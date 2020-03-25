#include <string>
#include <vector>

struct ImFont;

namespace tracy
{

class Worker;

class SourceView
{
    struct Line
    {
        const char* begin;
        const char* end;
    };

    struct AsmLine
    {
        uint64_t addr;
        std::string mnemonic;
        std::string operands;
    };

public:
    SourceView( ImFont* font );
    ~SourceView();

    void Open( const char* fileName, int line, uint64_t symAddr, const Worker& worker );
    void Render( const Worker& worker );

private:
    void RenderLine( const Line& line, int lineNum, uint32_t ipcnt, uint32_t iptotal );

    ImFont* m_font;
    const char* m_file;
    uint64_t m_symAddr;
    char* m_data;
    size_t m_dataSize;
    int m_targetLine;
    int m_selectedLine;

    std::vector<Line> m_lines;
    std::vector<AsmLine> m_asm;
};

}
#include <iostream>

enum class FontFamily
{
    classic = 0,
    stylish = 2,
    fancy = 3
};

enum class Style : unsigned short int
{
    None = 0,
    bold = 0x2,
    italic = 0x4,
    underline = 0x8
};

bool CheckFontSupport(FontFamily font = FontFamily::classic, unsigned short int style = 0)
{
    bool isSupported = true;
    bool isBoldItalic =  false;
    switch (font)
    {
    case FontFamily::fancy:
        // error if the font is fancy and the style is bold and italic
        isBoldItalic = (style == (unsigned short int)Style::bold) & ((unsigned short int)Style::italic);
        if (isBoldItalic)
        {
            std::clog << "Error: Fancy font cannot be bold italic." << std::endl;
            isSupported = false;
        }
        break;
    case FontFamily::classic:
        // error if the font is classic and the style is undeline
        if (style == (unsigned short int)Style::underline)
        {
            std::clog << "Error: Classic font cannot be underlined." << std::endl;
            isSupported = false;
        }
        break;
    default:
        /* otherwise*/
        break;
    }

    return isSupported;
}

int main()
{

    // check if the font family fancy supports the style  bold italic
    if (CheckFontSupport(FontFamily::fancy, (unsigned short int)Style::bold | (unsigned short int)Style::italic))
    {
        std::clog << "Fancy font supports the style bold italic." << std::endl;
    }

    // check if the font family classic supports the style underline
    if (CheckFontSupport(FontFamily::classic, (unsigned short int)Style::underline))
    {
        std::clog << "Classic font supports the style." << std::endl;
    }

    return 0;
}
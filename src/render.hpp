#pragma once

#include <cstdint>
#include <cstring>
#include <filesystem>
#include <string>
#include <string_view>

#include <imgui.h>

class WindowClass
{
public:
    static constexpr auto bufferSize = std::size_t{1024};
    static constexpr auto popUpFlags = ImGuiWindowFlags_NoResize   | ImGuiWindowFlags_NoMove |
                                       ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar;
    static constexpr auto popUpSize  = ImVec2(300.0F, 100.0F);
    static constexpr auto popUpButtonSize= ImVec2(120.0F,0.0F   );
	static constexpr auto popUpPos = ImVec2(1280.0F / 2.0F - popUpSize.x / 2.0F,
720.0F / 2.0F - popUpSize.y / 2.0F);

public:
    WindowClass() : currentFilename({})
    {
        std::memset(textBuffer,0,bufferSize);
    }

public:
    void Draw(std::string_view label);

private:
    void drawMenu     ();
    void drawSavePopup();
    void drawLoadPopup();
    void drawContent();
    void drawInfo();

    void saveToFile  (std::string_view filename);
    void loadFromFile(std::string_view filename);
    std::string getFileExtension(std::string_view filename);

private:
    char textBuffer[bufferSize];
    std::string currentFilename;
};

void render(WindowClass &window_obj);

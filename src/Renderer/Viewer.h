#pragma once
#include <vector>
#include <string>
#include <memory>
#include <filesystem>
#include <imgui.h>
#include <implot.h>

#include "Core/Log.h"
#include "Renderer/ImageLoader.h"

struct ViewData
{
    std::string name;
    std::string info;
    std::filesystem::path path;
    ImageTexture texture;

    ViewData(const std::string &name_, const std::string &info_, const std::filesystem::path &path_)
        : name(name_), info(info_), path(path_), texture(path_)
    {
    }
    ~ViewData() {}
    bool isValid() const { return texture.IsInitialized(); }
};

class Viewer
{
  public:
    Viewer();
    ~Viewer();

    // item management
    void ListItems();
    void ClearItems();
    void AddItem(const std::string &name, const std::string &info, const std::filesystem::path &path);

    void Update(); // draw the viewer

  private: // internal drawing methods
    void DrawItem(const int index);
    void DrawSideBySide();
    void DrawTabbed();

  private:
    bool m_SideBySide = false;
    std::vector<std::shared_ptr<ViewData>> m_Items;
    ImPlotRect m_AxesLimits;
};
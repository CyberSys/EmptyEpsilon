#ifndef DATABASE_VIEW_H
#define DATABASE_VIEW_H

#include "gui/gui2_element.h"

class ScienceDatabase;
class GuiListbox;

class DatabaseViewComponent : public GuiElement
{
public:
    DatabaseViewComponent(GuiContainer* owner);

    bool findAndDisplayEntry(string name);

private:
    P<ScienceDatabase> findEntryById(int32_t id);
    bool findAndDisplayEntry(string name, P<ScienceDatabase> parent);
    //Fill the selection listbox with options from the selected_entry, or the main database list if selected_entry is nullptr
    void fillListBox();
    void display();

    P<ScienceDatabase> selected_entry;
    GuiListbox* item_list = nullptr;
    GuiElement* keyvalue_container = nullptr;
    GuiElement* details_container = nullptr;

    static constexpr int navigation_width = 400;
};

#endif//DATABASE_VIEW_H

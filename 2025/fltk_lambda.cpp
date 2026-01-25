// this example came from google.
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/fl_ask.H> // For fl_alert

int main() {
    Fl_Window* window = new Fl_Window(300, 200, "Lambda Callback Example");
    Fl_Button* button = new Fl_Button(50, 50, 100, 30, "Click Me");
    button->color(FL_GREEN);

    // Non-capturing lambda
    button->callback([](Fl_Widget* w, void* user_data) {
            w->color(FL_RED);
    });

    window->end();
    window->show();
    return Fl::run();
}

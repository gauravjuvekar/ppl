from gi.repository import Gtk


class Handlers(object):
    def button_callback(self, entry):
        entry.set_text("Hello world")

    def quit(self, *args):
        Gtk.main_quit()

builder = Gtk.Builder()
builder.add_from_file("glade1.glade")

builder.connect_signals(Handlers())

window = builder.get_object("window1")
window.show_all()
Gtk.main()

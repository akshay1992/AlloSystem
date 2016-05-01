

#include "allocore/io/al_App.hpp"
#include "allocore/system/al_Parameter.hpp"
#include "alloGLV/al_ParameterGUI.hpp"

using namespace al;

Parameter Number("Number", "", 1.0, "", 0.0, 16);
Parameter Size("Size", "", 0.3, "", 0.1, 2.0);
Parameter Red("Red", "", 0.5, "", 0.0, 1.0);
Parameter Green("Green", "", 1.0, "", 0.0, 1.0);
Parameter Blue("Blue", "", 0.5, "", 0.0, 1.0);

PresetHandler presets("presetsGUI");

ParameterGUI gui;

class MyApp : public App
{
public:
	MyApp() {
		initWindow(Window::Dim(800,600), "Presets", 15);
		nav().pos(Vec3d(0,0,8));

		addCone(graphics().mesh());
		graphics().mesh().generateNormals();
		gui.setParentApp(this);

	}

	virtual void onDraw(Graphics &g) override
	{
		light();
		for (int i = 0; i < Number.get(); ++i) {
			g.pushMatrix();
			g.translate((i % 4) - 2, (i/4) - 2, -5);
			g.scale(Size.get());
			g.color(Red.get(), Green.get(), Blue.get());
			g.draw(g.mesh());
			g.popMatrix();
		}
	}

private:
	rnd::Random<> rng; // Random number generator
	Light light;
};


int main(int argc, char *argv[])
{
	presets << Number << Size << Red << Green << Blue; // Add parameters to preset handling

	// Now make control GUI
	// You can add Parameter objects or regular GLV Widgets using the
	// streaming operator. They will all be laid out vertically
	gui << new glv::Label("Presets example");
	gui << Number << Size;
	gui << new glv::Label("Color");
	gui << Red << Green << Blue;

	// Adding a PresetHandler to a ParameterGUI creates a multi-button interface
	// to control the presets.
	gui << presets;
	MyApp().start();
	return 0;
}

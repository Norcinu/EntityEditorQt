#ifndef VISUALISATION_H
#define VISUALISATION_H

#include <vector>

struct Entity
{
	void (*fndcl)(int, int, int);
	void * data;
};

class Visualisation
{
public:
	Visualisation(void);
	~Visualisation(void);

	bool Initialise(const int width, const int height);
	bool LoadEntity(const char *filename);
	void BeginScene();
	void EndScene();
	void Resize();
	void Move(const int x, const int y);

	int GetWidth() const { return panelWidth; }
	int GetHeight() const { return panelHeight; }

	void SetDimensions(const int h, const int w)
	{
		panelWidth = w;
		panelHeight = h;
	}

private:
	int panelWidth;
	int panelHeight;
	int xPosition;
	int yPosition;
	std::vector<Entity*> drawables;
};

#endif

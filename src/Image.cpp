#include "Image.h"

using namespace std;

Image::Image(){
	rect.x = 0;
	rect.y = 0;
	rect.w = 0;
	rect.h = 0;
}

void Image::load(int x, int y, int w, int h, SDL_Texture *t){
   tex = t;
   rect.x = x-w/2;
   rect.y = y-h/2;
   rect.w = w;
   rect.h = h;
}

void Image::render(SDL_Renderer *rend){
	SDL_RenderCopy(rend, tex, NULL, &rect);
}

bool Image::checkMouse(){
	int x, y;
	SDL_GetMouseState(&x, &y);
	if ((x>rect.x && x<rect.x+rect.w) && (y>rect.y && y<rect.y+rect.h)){
		return true;
	}
	return false;
}

Image::~Image(){
	SDL_DestroyTexture(tex);
}

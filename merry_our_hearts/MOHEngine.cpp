# include "MOHEngine.h"
using namespace MOHEngine;
Game::Game(){

  //Initialize sdl.
  Game::init("MERRY OUR HEARTS", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
             SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);
}
void Game::init(const char *t, int x, int y, int w, int h, bool fs)
{

  int flags = 0;
  if(fs)
    flags = SDL_WINDOW_FULLSCREEN;

  //Initialize Sdl.
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
    printf("SDL Inititalized\n");

    //Create window object.
    _window = SDL_CreateWindow(t, x, y ,w , h, flags);
    if(_window){
      printf("Game's window created.\n");

    }

    //Create renderer object.
    _renderer = SDL_CreateRenderer(_window, -1, 0);
    if(_renderer){
      printf("Games renderer initialized.\n");
      SDL_SetRenderDrawColor(_renderer, 255 ,255 ,255 ,255 );

    }

    _isRunning = true;

  }else{ //Sdl or one of games components faile to initialize.
    cerr << "One or more components faild to initialize!";
    _isRunning = false;

  }

}

void Game::update(){

}

void Game::draw(){
  SDL_RenderClear(_renderer);
  //Add objects to render.

  SDL_RenderPresent(_renderer);
}

void Game::clean(){

  //Free memory from sdl.
  SDL_DestroyWindow(_window);
  SDL_DestroyRenderer(_renderer);
  SDL_Quit();
}

void Game::handleEvents(Player* player){

  SDL_Event event;
  SDL_PollEvent(&event);

  //Perform function depending upon input.
  switch(event.type){
    case SDL_QUIT:
      _isRunning = false;
      printf("User exited the program\n");
      break;

    case SDLK_w:
      player -> MovingUp();
      break;

    case SDLK_s:
      player -> MovingDown();
      break;

    case SDLK_a:
      player -> MovingLeft();
      break;
    case SDLK_d:
      player -> MovingRight();
      break;
    case SDLK_KP_SPACE:
      player -> FireBullet();

      break;


    default:
      break;
    player -> ResetFlag();
  }
}
Game::~Game(){

}
SDL_Texture* TextureLoader::LoadSingleTexture(const char* texturePath, SDL_Renderer* ren){

  //Load file from given path and create texture.
  SDL_Surface* tmpSurface = IMG_Load(texturePath);
  SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tmpSurface);

  //Free surface object from memmory.
  SDL_FreeSurface(tmpSurface);
  //Return texture.
  return tex;

}

#include "WorldRenderer.h"
#include "../../main/Game.h"

namespace ch {

WorldRenderer::WorldRenderer() { }
WorldRenderer::~WorldRenderer() { }

void WorldRenderer::render(World& world) {
  auto& my_render_states = Game::getInstance()->getRenderstate();
  int map_front_x, map_front_y, map_end_x, map_end_y;
  sf::RenderStates render_states;
  render_states.transform.translate(my_render_states.cam_pos)
                         .scale(sf::Vector2f(my_render_states.cam_zoom, my_render_states.cam_zoom));
  
  // calculate pixel size to render
  map_front_x = 0;  // temp
  map_front_y = 0;
  map_end_x = 100;
  map_end_y = 100;
  
  // make vertexarray
  const int map_x = map_end_x - map_front_x;
  const int map_y = map_end_y - map_front_y;
  sf::VertexArray* vertex_arr = new sf::VertexArray[map_y];
  for(int i = 0; i != map_y; ++i) {
    vertex_arr[i] = sf::VertexArray(sf::TriangleStrip, (map_x << 1) + 2);
  }
  

  // set values
  //TODO
  const int map_x_2 = map_x << 2;
  for(int i = 0; i != map_y; ++i) {
    vertex_arr[i][0].position = sf::Vector2f(0, i);
    vertex_arr[i][1].position = sf::Vector2f(0, i + 1);

    vertex_arr[i][0].color = world.map_[i * map_x].getTileColor();
    vertex_arr[i][1].color = world.map_[i * map_x].getTileColor();

    for(int j = 1; j != (map_x + 1); ++j) {

      int jj = j << 1;
      vertex_arr[i][jj].position = sf::Vector2f(j, i);
      vertex_arr[i][jj + 1].position = sf::Vector2f(j, i + 1);

      vertex_arr[i][jj].color = world.map_[i * map_x + j - 1].getTileColor();
      vertex_arr[i][jj + 1].color = world.map_[i * map_x + j - 1].getTileColor();

    }

  }

  //render
  for(int i = 0; i != map_y; ++i) {
    Game::getInstance()->getWindow().draw(vertex_arr[i], render_states);
  }
  
  delete[] vertex_arr;

}


}
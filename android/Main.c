#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
//#include <SDL/SDL_main.h>
#include "SDL2/SDL_ttf.h"
#include <time.h>
#include <jni.h>
#include <errno.h>

//#include <android_native_app_glue.h>


#include "unwind.h"
#include <android/log.h>
//#include <android_native_app_glue.h>
#include <unistd.h>
//#include <pthread.h>


#define MAX_VERTEX_MEMORY 512 * 1024
#define MAX_ELEMENT_MEMORY 128 * 1024
#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_IMPLEMENTATION
#define NK_SDL_GLES2_IMPLEMENTATION
#define MAAndroidATH 1024

#include "nuklear.h"
#include "nuklear_sdl_gles2.h"
#include "style.c"
#include "ui.c"
//#include "Beijing.h"
#include "overview.c"
#include "node_editor.c"
    /*GUI 画*/
int *guixx(SDL_Window *win) {

  float bg[4];
  //局部变量宽高
  int   win_width, win_height;
  /*函数：背景颜色*/
  nk_color_fv(bg, nk_rgb(225, 225, 225));
  /*函数：SDL获取窗口大小*/
  SDL_GetWindowSize(win, &win_width, &win_height);
  
  glViewport(0, 0, win_width, win_height);
  //清除
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(bg[0], bg[1], bg[2], bg[3]);
  
  /* 重要提示`nk_sdl_render`修改了 全局 OpenGL */
 
  nk_sdl_render(NK_ANTI_ALIASING_ON, MAX_VERTEX_MEMORY, MAX_ELEMENT_MEMORY);
  //SDL与GL交换窗口
  SDL_GL_SwapWindow(win);
   return 0;
}

struct nk_context *ctx;

int main(int argc, char *argv[]) 
{
  //__android_log_print(ANDROID_LOG_INFO, "sdltest", "SDL_main started");
  
 
  SDL_GLContext      glContext;
  /* SDL setup */
  SDL_SetHint(SDL_HINT_VIDEO_HIGHDPI_DISABLED, "0");
  SDL_GL_SetAttribute(
  SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  
  SDL_Window *win = SDL_CreateWindow("JNCKGUI_Android", SDL_WINDOWPOS_CENTERED,
  SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
  glContext       = SDL_GL_CreateContext(win);
  int   w, h;
  float dpi, bpi, cpi;
  SDL_GetWindowSize(win, &w, &h);
  int index = SDL_GetWindowDisplayIndex(win);
  int ret   = SDL_GetDisplayDPI(index, &bpi, &dpi, &cpi);
  /*像素大小*/
  float mult = -1 == ret ? 2 : (bpi / 96);
 
//前景图片显示
  /*SDL_Renderer *renderer =
  SDL_CreateRenderer(win, -1, SDL_RENDERER_TARGETTEXTURE);
  char *bmp = Getthecurrentdirectorybmp("/resources/shili.png");
  SDL_Texture *texBack = IMG_LoadTexture(renderer, bmp);
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texBack, NULL, NULL);
  SDL_RenderPresent(renderer);      //踢脚线斜长
  */
  //sleep(10);
  /*
  //渲染层
 SDL_Renderer *renderer = SDL_CreateRenderer(win, -1, 1);
  char *        bmp      = Getthecurrentdirectorybmp("/resources/shili.bmp");
  SDL_Surface * pic      = SDL_LoadBMP(bmp);
  //载入的图片生成SDL材质
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, pic);
  //把材质复制到渲染器
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  //显示出来
  SDL_RenderPresent(renderer);
  sleep(1);*/

  
  //__android_log_print(ANDROID_LOG_INFO, "sdltest", "screen: %dx%d %f mult",w,h, mult);
  /*OpenGL setup */
  glViewport(0, 0, w, h);

  ctx = nk_sdl_init(win);
  {
    struct nk_font_atlas *atlas;
    int       font_pixel_heig = 25;
    //加载光标
    // nk_style_load_all_cursors(ctx, atlas->cursors);
    //字库初始化
    nk_sdl_font_stash_begin(&atlas);
    // NK字体ATLAS添加默认字体不支持中文
    //  atlas->default_font =nk_font_atlas_add_default(atlas, 10 * mult, 0);
    //加载定义字库
    struct nk_font_config config = nk_font_config(font_pixel_heig);
    config.merge_mode           = nk_false;
    config.oversample_h          = 1;
    config.oversample_v          = 1;
    // config.range = &china_ttf[0]; //自己定义支持中文
    //自带编码支持中文
    config.range = nk_font_chinese_glyph_ranges();
    // config.coord_type = NK_COORD_UV; //附值0
    //获取字库
    


    char *buffchar = Getthecurrentdirecyttf(
        "/resources/方正宋三_GBK.ttf");
    struct nk_font *font =
    nk_font_atlas_add_from_file(atlas, buffchar, font_pixel_heig, &config);
 
    //字库调用结束
    nk_sdl_font_stash_end();
    font->handle.height *= 2.0f;
    nk_style_set_font(ctx, &font->handle);
    nk_font_atlas_end(atlas, font->texture, NULL);
  }
  /* style.h主题*/
  /////////////////////
  //set_style(ctx, THEME_WHITE);
  ////////////////////
  int quit = 0;
  while (!quit) {
    SDL_Event e;
    nk_input_begin(ctx);
    if (SDL_WaitEvent(&e) != 0) {
      if (e.type == SDL_QUIT ||
          (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_AC_BACK))
        break;
      
      //__android_log_print(ANDROID_LOG_INFO, "sdltest", "event: %x", e.type);
      nk_sdl_handle_event(&e);
     //加载窗口
       render_gui(ctx, win, w, h, mult);

       //overview(ctx);
    }
    //  int j = 2;
    //  pthread_t tid;
    //创建线程
    // pthread_create(&tid, NULL, guixx(win), &j);
    guixx(win);
    nk_input_end(ctx);
//    node_editor(ctx);
  }
  nk_sdl_shutdown();

  SDL_GL_DeleteContext(glContext);
//  SDL_DestroyTexture(texBack);
  SDL_DestroyWindow(win);
  SDL_Quit();
  exit(0);
}
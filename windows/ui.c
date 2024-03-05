
#define MAAndroidATH 1024

typedef struct
{

  /*一层铺装水平到平台铺装水平(高度) */
  float Platform_high;
  /*踏步立面板高度*/
  float Façade_Height;
  /*踏步立面板数量 */
  float Fourth_quantity;
  /*踏步长*/
  float Stepping;
  /*立面面积*/
  float Facade;

  /*踏面总长度*/
  float Length_first;
  /*踏步面板宽度 */
  float Step_width;
  /*踏步面板厚度*/
  float Step_ping;
  /*踏步面板数量 */
  float Step_quantity;
  /*踏面板出立面板*/
  float Stealing_panel_outlet;
  /*踏面面积*/
  float Pedicle_area;
} data;

void Stand_calculation(data *t)
{
  /*踏步立面板数量 高度*/
  t->Façade_Height = t->Platform_high / t->Fourth_quantity - t->Step_ping;
}

void Panel_calculation(data *p)
{
  /*踏步面板数量 宽度*/
  p->Step_width =
      p->Length_first / p->Fourth_quantity + p->Stealing_panel_outlet;
}

typedef struct
{
  /*平台长 */
  float Platform_length;
  /*平台宽*/
  float Platform_wide;
  /*平台面积*/
  float Platform_area;
  /*平台尺寸*/
  float Platform_size;
  /*平台板数量*/
  float Platform_quantity;
  /*平台长轴等分*/
  float Platform_X_axis_equivalent;
  /*平台宽轴等分*/
  float Platform_Y_axis_equivalent;

} data_b;

void Triangular_calculation(data_b *s)
{
  /*踏步平台面板 长*/
  s->Platform_length = s->Platform_length / s->Platform_X_axis_equivalent;

  /*踏步平台面板 宽*/
  s->Platform_wide = s->Platform_wide / s->Platform_Y_axis_equivalent;

  /*踏步平台面板数量 */
  s->Platform_quantity =
      s->Platform_X_axis_equivalent * s->Platform_Y_axis_equivalent;

  /*踏步平台面板面积 */
  s->Platform_area =
      s->Platform_length * s->Platform_wide * s->Platform_quantity / 1000000;
}

typedef struct
{

  /*三角数量 */
  float Triangular_quantity;
  /*三角宽边*/
  float Triangle_wide;
  /*三角高边*/
  float Triangle_height;
  /*三角斜边*/
  float Triangle_Oblique;
  /*三角面积*/
  float Triangle_area;

  /*踢脚线长*/
  float Kick_length;
  /*踢脚线高*/
  float Kick_high;
  /*踢脚线斜长*/
  float Skating_line;
  /*踢脚线等分*/
  float King_line;
  /*踢脚线面积*/
  float Kick_area;

} data_c;

void Triangle_kick(data_c *j)
{
  /*三角踢脚线*/
  j->Triangle_Oblique = j->Triangle_height * j->Triangle_wide;

  /*踢脚线长等分*/
  j->Kick_length = j->Skating_line / j->King_line;

  /*面积计算*/
  j->Kick_area = (j->Kick_length * j->Kick_high) * j->King_line * 0.000001;
}

typedef struct
{
  data Tab;
  data Steal;
  data_b Platform;
  data_c Triangular;
} Total_data;

// 结构声明

static char text[9][64];
static int text_len[9];
static char box_buffer[1024];
static int box_len;

char buf0[256] = "";
char buf[256] = "软件用途说明：\0";
char buf1[256] = "(1)：石材护栏花瓶间隔计算，石材栏板间隔计算\0";
char buf2[256] = "(2)：石材斜护栏花瓶间隔计算，石材栏板等分计算\0";
char buf3[256] = "(3)：软件用途比较全面，包括(石，铁，木) \0";
char buf4[256] = "(4)：更多用途可以自己摸索发现 \0";
// 地面水平到平台水平
char buf_Platform_high[256] = "1800";
// 踏步长度
char buf_Tab_Stepping[256] = "1100";
// 踏步面板数量
char buf_Tab_Fourth_quantity[256] = " 12";
// 踏步面板厚度
char buf_Tab_Step_ping[256] = "40";
// 踏面总长度
char buf_Steal_Length_first[256] = "3600";
// 凸出踏面
char buf_Steal_Stealing_panel_outlet[256] = "20";
// 平台长度
char buf_Platform_Platform_length[256] = "2100";
// 平台宽度
char buf_Platform_Platform_wide[256] = "1200";
// 平台长等分
char buf_Platform_Platform_X_axis_equivalent[256] = "2";
// 平台宽等分
char buf_Platform_Platform_Y_axis_equivalent[256] = "2";
// 踢脚线高"
char buf_Triangular_Kick_high[256] = "120";
// 踢脚线长等分
char buf_Triangular_King_line[256] = "3";

static double a = 0, b = 0, c = 0, d = 0, e = 0,
              f = 0, g = 0, h = 0, i = 0,
              j = 0, k = 0, l = 0;
static double *current = &a;
static double *current1 = &b;
static double *current2 = &c;
static double *current3 = &d;
static double *current4 = &e;
static double *current5 = &f;
static double *current6 = &g;
static double *current7 = &h;
static double *current8 = &i;
static double *current9 = &j;
static double *current10 = &k;
static double *current11 = &l;
static int len;

// char buffttf[MAAndroidATH];
// /*获取当前目录+ttf*/
// char *
// Getthecurrentdirecyttf(const char *filename)
// {
//   getcwd(buffttf, MAAndroidATH);
//   strcat(buffttf, filename);
//   return buffttf;
// }
// char buffbmp[MAAndroidATH];
// /*获取当前目录+bmp*/
// char *
// Getthecurrentdirectorybmp(const char *filename)
// {
//   getcwd(buffbmp, MAAndroidATH);
//   strcat(buffbmp, filename);
//   return buffbmp;
// }

/*渲染GUI*/
static void *
render_gui(struct nk_context *ctx, SDL_Window *win, int w, int h)
{
  int RH = h / 10;

  if (nk_begin(ctx, "楼梯铺装下料算器", nk_rect(0, 0, w, h),
               NK_WINDOW_CLOSABLE |
                   NK_WINDOW_MINIMIZABLE |
                   NK_WINDOW_MINIMIZABLE |
                   NK_WINDOW_TITLE |
                   NK_WINDOW_SCROLL_AUTO_HIDE
               /* NK_WINDOW_NO_SCROLLBAR*/))
  {

    enum
    {
      One0,
      Two1,
      Three2,
      Four3
    };
    static int op = One0;
    enum
    {
      One,
      Two,
      Three,
      Four,
      Zz
    };
    static int lop = Three;
    static int selected_item = 0;

    static int popup_active;
    /*函数：调整控件宽高NK布局行静态*/
    // nk_layout_row_static(ctx, 150, RH, 3);
    /*函数：调整控件宽度NK布局行动态*/
    nk_layout_row_dynamic(ctx, RH / 2, 3);
    if (nk_button_label(ctx, "开始计算"))
    {
      /* if (op == One0) { add_d(&data); }
       if (op == Two1) { add_y(&data); }
       if (op == Three2) { add_b(&data); }
       if (op == Four3) { add_dd(&data); }*/
      Total_data data;
      if (selected_item == 0)
      {

        // 地面水平到平台水平
        *current = atof(buf_Platform_high);
        data.Tab.Platform_high = *current;
        // 踏步长度
        *current1 = atof(buf_Tab_Stepping);
        data.Tab.Stepping = *current1;
        // 踏步面板数量
        *current2 = atof(buf_Tab_Fourth_quantity);
        data.Tab.Fourth_quantity = *current2;
        // 踏步面板厚度
        *current3 = atof(buf_Tab_Step_ping);
        data.Tab.Step_ping = *current3;

        /*立板计算公式*/
        Stand_calculation(&data.Tab);
        //  Panel_calculation(&data.Steal);
        /*踏步面积*/
        data.Tab.Facade = (data.Tab.Stepping * data.Tab.Façade_Height) *
                          data.Tab.Fourth_quantity * 0.000001;

        /*printf("踏步立板高%d(mm)\n踏步立板数量%d(块)\n踏步长%d(mm)\n立面积%f(㎡)",
                data.Tab.Façade_Height, data.Tab.Fourth_quantity, data.Tab.Stepping,
                data.Tab.Facade);*/

        // 踏步立板高
        if (text_len[7] = snprintf(text[7], sizeof(&data.Tab.Façade_Height), "%.2f",
                                   data.Tab.Façade_Height))
        {

          /*  text[7][text_len[7]] = '\n';
            text_len[7]++;*/

          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
        // n踏步立板数量
        if (text_len[7] = snprintf(text[7], sizeof(&data.Tab.Fourth_quantity),
                                   "%.2f", data.Tab.Fourth_quantity))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }

        // n踏步长
        if (text_len[7] = snprintf(text[7], sizeof(&data.Tab.Stepping), "%.2f",
                                   data.Tab.Stepping))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }

        // 立面板面积
        if (text_len[7] = snprintf(text[7], sizeof(&data.Tab.Facade),
                                   "%.2f", data.Tab.Facade))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }

        // 踏面总长度
        *current4 = atof(buf_Steal_Length_first);
        data.Steal.Length_first = *current4;
        // 踏面板凸出立面板
        *current5 = atof(buf_Steal_Stealing_panel_outlet);
        data.Steal.Stealing_panel_outlet = *current5;

        /*踏面数量*/
        data.Steal.Fourth_quantity = data.Tab.Fourth_quantity;
        Panel_calculation(&data.Steal);
        /*踏面长*/
        data.Steal.Length_first = data.Tab.Stepping;
        /*踏面面积*/
        data.Steal.Pedicle_area = (data.Steal.Step_width * data.Steal.Length_first) *
                                  data.Steal.Fourth_quantity * 0.000001;
        /*printf("踏步面板宽%d(mm)\n踏步面板数量%d(块)\n踏面面积%2f(㎡)",
                data.Steal.Step_width, data.Steal.Fourth_quantity,
                data.Steal.Pedicle_area);*/
        // 踏步面板宽
        if (text_len[7] = snprintf(text[7], sizeof(&data.Steal.Step_width), "%.2f", data.Steal.Step_width))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
        // n踏步长
        if (text_len[7] = snprintf(text[7], sizeof(&data.Tab.Stepping), "%.2f", data.Tab.Stepping))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &buf_Steal_Length_first, (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
        // n踏步面板数量
        if (text_len[7] = snprintf(text[7], sizeof(&data.Steal.Fourth_quantity), "%.2f", data.Steal.Fourth_quantity))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
        // n踏面面积
        if (text_len[7] = snprintf(text[7], sizeof(&data.Steal.Pedicle_area), "%.2f", data.Steal.Pedicle_area))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }

        // 平台长度
        *current6 = atof(buf_Platform_Platform_length);
        data.Platform.Platform_length = *current6;
        // 平台宽度
        *current7 = atof(buf_Platform_Platform_wide);
        data.Platform.Platform_wide = *current7;
        // 平台长等分
        *current8 = atof(buf_Platform_Platform_X_axis_equivalent);
        data.Platform.Platform_X_axis_equivalent = *current8;
        // 平台宽等分
        *current9 = atof(buf_Platform_Platform_Y_axis_equivalent);
        data.Platform.Platform_Y_axis_equivalent = *current9;

        /*平台数据*/
        Triangular_calculation(&data.Platform);

        /*printf( "平台面板长%f(mm)\n平台面板宽%f(mm)\n平台面板数量%d(块)\n平台面积%2f(㎡)"
            "\n",
            data.Platform.Platform_length, data.Platform.Platform_wide,
            data.Platform.Platform_quantity,
            data.Platform.Platform_area);*/

        // 平台面板长
        if (text_len[7] = snprintf(text[7], sizeof(&data.Platform.Platform_length), "%.2f",
                                   data.Platform.Platform_length))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
        // n平台面板宽
        if (text_len[7] = snprintf(text[7], sizeof(&data.Platform.Platform_wide), "%.2f",
                                   data.Platform.Platform_wide))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
        // n平台面板数量
        if (text_len[7] = snprintf(text[7], sizeof(&data.Platform.Platform_quantity), "%.2f",
                                   data.Platform.Platform_quantity))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
        // n平台面积
        if (text_len[7] = snprintf(text[7], sizeof(&data.Platform.Platform_area), "%.2f",
                                   data.Platform.Platform_area))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }

        // 三角
        /*三角高*/
        data.Triangular.Triangle_height = data.Tab.Façade_Height + data.Tab.Step_ping;
        /*三角宽*/
        data.Triangular.Triangle_wide = data.Steal.Step_width;
        /*三角数量*/
        data.Triangular.Triangular_quantity = data.Steal.Fourth_quantity;
        Triangle_kick(&data.Triangular);
        /*勾股*/
        data.Triangular.Triangle_Oblique =
            (int)sqrt(data.Triangular.Triangle_wide * data.Triangular.Triangle_wide +
                      data.Triangular.Triangle_wide * data.Triangular.Triangle_wide);
        /*三角面积*/
        data.Triangular.Triangle_area =
            ((data.Triangular.Triangle_height * data.Triangular.Triangle_wide) / 2) *
            data.Triangular.Triangular_quantity * 0.000001;
        /* printf(
               "三角高%d(mm)\n三角宽%d(mm)\n三角斜%d(mm)\n三角数量%d(块)\n三角面积%2f("
               "㎡)",
               data.Triangular.Triangle_height, data.Triangular.Triangle_wide,
               data.Triangular.Triangle_Oblique, data.Triangular.Triangular_quantity,
               data.Triangular.Triangle_area);*/
        // 三角高
        if (text_len[7] = snprintf(text[7], sizeof(&data.Triangular.Triangle_height), "%.2f",
                                   data.Triangular.Triangle_height))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
        // n三角宽
        if (text_len[7] = snprintf(text[7], sizeof(&data.Triangular.Triangle_wide), "%.2f",
                                   data.Triangular.Triangle_wide))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
        // n三角斜
        if (text_len[7] = snprintf(text[7], sizeof(&data.Triangular.Triangle_Oblique), "%.2f",
                                   data.Triangular.Triangle_Oblique))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
        // n三角数量
        if (text_len[7] = snprintf(text[7], sizeof(&data.Triangular.Triangular_quantity), "%.2f",
                                   data.Triangular.Triangular_quantity))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
        // n三角面积
        if (text_len[7] = snprintf(text[7], sizeof(&data.Triangular.Triangle_area), "%.2f",
                                   data.Triangular.Triangle_area))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }

        // 踢脚线
        /*水平高*/
        data.Triangular.Kick_high = data.Tab.Platform_high;
        /*踏步长*/
        data.Triangular.Kick_length = data.Steal.Length_first;
        /*调用一算法*/
        Triangle_kick(&data.Triangular);
        /*勾股踢脚线长*/
        data.Triangular.Skating_line =
            (int)sqrt(data.Triangular.Kick_high * data.Triangular.Kick_high +
                      data.Steal.Length_first * data.Steal.Length_first);

        // 踢脚线高
        *current10 = atof(buf_Triangular_Kick_high);
        data.Triangular.Kick_high = *current10;
        // 踢脚线长等分
        *current11 = atof(buf_Triangular_King_line);
        data.Triangular.King_line = *current11;

        /*printf("踢脚线斜长%2f(mm)\n", data.Triangular.Skating_line);
        len = snprintf(buf_interval, 256, "%2f\n", data.Triangular.Skating_line);*/
        /*调用第二_三算法*/
        Triangle_kick(&data.Triangular);
        /*  printf(
            "踢脚线高%d(mm)\n踢脚线长%2f(mm)\n踢脚线长等分%d(块)\n踢脚线面积%2f\n",
            data.Triangular.Kick_high, data.Triangular.Kick_length,
            data.Triangular.King_line, data.Triangular.Kick_area);*/
        // 踢脚线高
        if (text_len[17] = snprintf(text[17], sizeof(&data.Triangular.Kick_high), "", data.Triangular.Kick_high))
        {
          text[17][text_len[17]] = '\n';
          text_len[17]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[17];
          text_len[17] = 0;
        }

        // 踢脚线斜长
        if (text_len[7] = snprintf(text[7], sizeof(&data.Triangular.Skating_line),
                                   "%.2f", data.Triangular.Skating_line))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
        // n踢脚线长
        if (text_len[7] = snprintf(text[7], sizeof(&data.Triangular.Kick_length),
                                   "%.2f", data.Triangular.Kick_length))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }

        // n踢脚线长等分
        if (text_len[7] = snprintf(text[7], sizeof(&data.Triangular.King_line), "%.2f",
                                   data.Triangular.King_line))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
        // n踢脚线面积
        if (text_len[7] = snprintf(text[7], sizeof(&data.Triangular.Kick_area), "%.2f",
                                   data.Triangular.Kick_area))
        {
          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }
      }
      if (selected_item == 1)
      { // add_y(&data);
      }
      if (selected_item == 2)
      { // add_b(&data);
      }
      if (selected_item == 3)
      { // add_dd(&data);
      }
    }
    //   len = snprintf(buf_interval, 256, "%f", data.interval);

    /*  nk_layout_row_dynamic(ctx, RH / 4, 1);
        nk_label(ctx, "地面水平到平台水平高度[mm]:", NK_TEXT_LEFT);
        nk_flags event = nk_edit_string_zero_terminated(
            ctx, NK_EDIT_SIMPLE, buf_Platform_high, 36, nk_filter_float);

        if (event & NK_EDIT_ACTIVATED) { SDL_StartTextInput(); }

        if (event & NK_EDIT_DEACTIVATED) { SDL_StopTextInput(); }
        */

    if (nk_button_label(ctx, "清空输入"))
    {
      // 清空数组
      nk_memset(buf_Platform_high, 0, sizeof(buf_Platform_high));
      nk_memset(buf_Tab_Stepping, 0, sizeof(buf_Tab_Stepping));
      nk_memset(
          buf_Tab_Fourth_quantity, 0, sizeof(buf_Tab_Fourth_quantity));
      nk_memset(buf_Tab_Step_ping, 0, sizeof(buf_Tab_Step_ping));

      nk_memset(buf_Steal_Length_first, 0, sizeof(buf_Steal_Length_first));
      nk_memset(buf_Steal_Stealing_panel_outlet, 0,
                sizeof(buf_Steal_Stealing_panel_outlet));
      nk_memset(buf_Platform_Platform_length, 0,
                sizeof(buf_Platform_Platform_length));
      nk_memset(buf_Platform_Platform_wide, 0,
                sizeof(buf_Platform_Platform_wide));

      nk_memset(buf_Platform_Platform_X_axis_equivalent, 0,
                sizeof(buf_Platform_Platform_X_axis_equivalent));
      nk_memset(buf_Platform_Platform_Y_axis_equivalent, 0,
                sizeof(buf_Platform_Platform_Y_axis_equivalent));
      nk_memset(
          buf_Triangular_Kick_high, 0, sizeof(buf_Triangular_Kick_high));
      nk_memset(
          buf_Triangular_King_line, 0, sizeof(buf_Triangular_King_line));
      nk_memset(box_buffer, 000, sizeof(box_buffer));
    }

    if (nk_button_label(ctx, "使用说明"))
      //     nk_layout_row_push(ctx, RH);
      popup_active = 1;
    // nk_layout_row_end(ctx);
    if (popup_active)
    {
      static struct nk_rect s = {80, 1000, 910, 500};
      if (nk_popup_begin(ctx, NK_POPUP_STATIC, "root", 0, s))
      {
        nk_layout_row_dynamic(ctx, RH / 2, 1);
        nk_label(ctx, "使用说明：看png图解 ", NK_TEXT_LEFT);
        nk_label(ctx, "1：软件是免费的，可以复制，使用，传播", NK_TEXT_LEFT);
        nk_label(ctx, "2：软件版权归@ by：jnck所有 WX：snd8899",
                 NK_TEXT_LEFT);
        // nk_label(ctx, "作者：Jnck   WX：snd8899\0ghjhh ", NK_TEXT_LEFT);

        nk_layout_row_dynamic(ctx, RH / 3, 1);
        if (nk_button_label(ctx, "确定"))
        {
          popup_active = 0;
          nk_popup_close(ctx);
        }
        /*  if (nk_button_label(ctx, "取消")) {
            popup_active = 0;
            nk_popup_close(ctx);
          }*/
        nk_popup_end(ctx);
      }
      else
        popup_active = nk_false;
    }

    /*函数：调整控件宽度NK布局行动态*/
    nk_layout_row_dynamic(ctx, RH / 2, 5);

    if (nk_option_label(ctx, "灰色", lop == Zz))
    {

      lop = Zz;

      set_style(ctx, 5);
    }

    //  set_style(ctx, 5);

    if (nk_option_label(ctx, "白色", lop == One))
    {
      /*选择按钮事件*/
      lop = One;
      /* style.h主题*/
      set_style(ctx, THEME_WHITE);
    }
    if (nk_option_label(ctx, "黑色", lop == Two))
    {
      /*选择按钮事件*/
      lop = Two;
      /* style.h主题*/
      set_style(ctx, THEME_BLACK);
    }
    if (nk_option_label(ctx, "蓝色", lop == Three))
    {
      /*选择按钮事件*/
      lop = Three;
      /* style.h主题*/
      set_style(ctx, THEME_BLUE);
    }
    if (nk_option_label(ctx, "红色", lop == Four))
    {
      /*选择按钮事件*/
      /* style.h主题*/
      lop = Four;
      set_style(ctx, THEME_RED);
    }

    /*函数：调整控件宽度NK布局行动态*/
    if (nk_tree_push(ctx, NK_TREE_TAB, "双跑梯-带平台", NK_MINIMIZED))
    {
      nk_layout_row_dynamic(ctx, RH / 4, 1);
      nk_label(ctx, "地面水平到平台水平高度[mm]:", NK_TEXT_LEFT);
      nk_flags event = nk_edit_string_zero_terminated(
          ctx, NK_EDIT_SIMPLE, buf_Platform_high, 36, nk_filter_float);

      if (event & NK_EDIT_ACTIVATED)
      {
        SDL_StartTextInput();
      }

      if (event & NK_EDIT_DEACTIVATED)
      {
        SDL_StopTextInput();
      }

      nk_layout_row_dynamic(ctx, RH / 4, 1);
      nk_label(ctx, "踏面总宽度 [mm]:", NK_TEXT_LEFT);
      nk_flags event3 = nk_edit_string_zero_terminated(
          ctx, NK_EDIT_SIMPLE, buf_Steal_Length_first, 36, nk_filter_float);

      if (event3 & NK_EDIT_ACTIVATED)
      {
        SDL_StartTextInput();
      }

      if (event3 & NK_EDIT_DEACTIVATED)
      {
        SDL_StopTextInput();
      }

      nk_layout_row_dynamic(ctx, RH / 4, 1);
      nk_label(ctx, "踏面长度 [mm]:", NK_TEXT_LEFT);
      nk_flags event33 = nk_edit_string_zero_terminated(
          ctx, NK_EDIT_SIMPLE, buf_Tab_Stepping, 36, nk_filter_float);

      if (event33 & NK_EDIT_ACTIVATED)
      {
        SDL_StartTextInput();
      }

      if (event33 & NK_EDIT_DEACTIVATED)
      {
        SDL_StopTextInput();
      }

      nk_layout_row_dynamic(ctx, RH / 4, 1);
      nk_label(ctx, "踏步数量[mm]:", NK_TEXT_LEFT);

      nk_flags event1 = nk_edit_string_zero_terminated(
          ctx, NK_EDIT_SIMPLE, buf_Tab_Fourth_quantity, 36, nk_filter_float);

      if (event1 & NK_EDIT_ACTIVATED)
      {
        SDL_StartTextInput();
      }

      if (event1 & NK_EDIT_DEACTIVATED)
      {
        SDL_StopTextInput();
      }

      nk_layout_row_dynamic(ctx, RH / 4, 1);
      nk_label(ctx, "踏步面板厚度[mm]:", NK_TEXT_LEFT);
      nk_flags event2 = nk_edit_string_zero_terminated(
          ctx, NK_EDIT_SIMPLE, buf_Tab_Step_ping, 36, nk_filter_float);
      if (event2 & NK_EDIT_ACTIVATED)
      {
        SDL_StartTextInput();
      }

      if (event2 & NK_EDIT_DEACTIVATED)
      {
        SDL_StopTextInput();
      }

      nk_layout_row_dynamic(ctx, RH / 4, 1);
      nk_label(ctx, "踏面板凸出立面板[mm]:", NK_TEXT_LEFT);

      nk_flags event4 = nk_edit_string_zero_terminated(
          ctx, NK_EDIT_SIMPLE, buf_Steal_Stealing_panel_outlet, 36, nk_filter_float);

      if (event4 & NK_EDIT_ACTIVATED)
      {
        SDL_StartTextInput();
      }

      if (event4 & NK_EDIT_DEACTIVATED)
      {
        SDL_StopTextInput();
      }
      // 平台数据

      nk_layout_row_dynamic(ctx, RH / 4, 1);
      nk_label(ctx, "平台总长 [mm]:", NK_TEXT_LEFT);
      nk_flags event5 = nk_edit_string_zero_terminated(
          ctx, NK_EDIT_SIMPLE, buf_Platform_Platform_length, 36, nk_filter_float);
      if (event5 & NK_EDIT_ACTIVATED)
      {
        SDL_StartTextInput();
      }

      if (event5 & NK_EDIT_DEACTIVATED)
      {
        SDL_StopTextInput();
      }

      nk_layout_row_dynamic(ctx, RH / 4, 1);
      nk_label(ctx, "平台总宽[mm]:", NK_TEXT_LEFT);
      nk_flags event6 = nk_edit_string_zero_terminated(
          ctx, NK_EDIT_SIMPLE, buf_Platform_Platform_wide, 36, nk_filter_float);

      if (event6 & NK_EDIT_ACTIVATED)
      {
        SDL_StartTextInput();
      }

      if (event6 & NK_EDIT_DEACTIVATED)
      {
        SDL_StopTextInput();
      }

      nk_layout_row_dynamic(ctx, RH / 4, 1);
      nk_label(ctx, "平台长等分[块]:", NK_TEXT_LEFT);

      nk_flags event7 = nk_edit_string_zero_terminated(
          ctx, NK_EDIT_SIMPLE, buf_Platform_Platform_X_axis_equivalent, 36, nk_filter_float);

      if (event7 & NK_EDIT_ACTIVATED)
      {
        SDL_StartTextInput();
      }

      if (event7 & NK_EDIT_DEACTIVATED)
      {
        SDL_StopTextInput();
      }

      nk_layout_row_dynamic(ctx, RH / 4, 1);
      nk_label(ctx, "平台宽等分[块]:", NK_TEXT_LEFT);
      nk_flags event8 = nk_edit_string_zero_terminated(
          ctx, NK_EDIT_SIMPLE, buf_Platform_Platform_Y_axis_equivalent, 36, nk_filter_float);
      if (event8 & NK_EDIT_ACTIVATED)
      {
        SDL_StartTextInput();
      }

      if (event8 & NK_EDIT_DEACTIVATED)
      {
        SDL_StopTextInput();
      }

      nk_layout_row_dynamic(ctx, RH / 4, 1);
      nk_label(ctx, "踢脚线高[mm]:", NK_TEXT_LEFT);
      nk_flags event9 = nk_edit_string_zero_terminated(
          ctx, NK_EDIT_SIMPLE, buf_Triangular_Kick_high, 36, nk_filter_float);
      if (event9 & NK_EDIT_ACTIVATED)
      {
        SDL_StartTextInput();
      }
      if (event9 & NK_EDIT_DEACTIVATED)
      {
        SDL_StopTextInput();
      }

      nk_layout_row_dynamic(ctx, RH / 4, 1);
      nk_label(ctx, "踢脚线斜长等分[块]:", NK_TEXT_LEFT);
      nk_flags event10 = nk_edit_string_zero_terminated(
          ctx, NK_EDIT_SIMPLE, buf_Triangular_King_line, 36, nk_filter_float);
      if (event10 & NK_EDIT_ACTIVATED)
      {
        SDL_StartTextInput();
      }
      if (event10 & NK_EDIT_DEACTIVATED)
      {
        SDL_StopTextInput();
      }

      /*nk_layout_row_dynamic(ctx, RH / 4, 1);
      nk_flags event11 = nk_edit_string_zero_terminated(
     ctx, NK_EDIT_SIMPLE, buf_railing_width, 36, nk_filter_float);

  if (event11 & NK_EDIT_ACTIVATED) { SDL_StartTextInput(); }

  if (event11 & NK_EDIT_DEACTIVATED) { SDL_StopTextInput(); }
  */
      nk_tree_pop(ctx);
    }

    /*  if (event3& NK_EDIT_ACTIVATED) { SDL_StartTextInput(); }
  if (event3& NK_EDIT_DEACTIVATED) { SDL_StopTextInput(); }*/

    /*函数;单选框

      nk_layout_row_dynamic(ctx, RH / 2, 3);

      if (nk_option_label(ctx, "两边有间隔", op == One0)) { op = One0; }
      if (nk_option_label(ctx, "两边没有间隔", op == Two1)) { op = Two1; }
      if (nk_option_label(ctx, "单边有间隔", op == Three2)) { op = Three2; }
      //  if (nk_option_label(ctx, "总长等分", op == Four3)) { op = Four3; }
  */
    static const char *items[] = {"双跑梯-带平台", "弧形梯-连续不带平台",
                                  "圆形梯-连续不带平台",
                                  "拐角梯-连续不带平台"};
    enum
    {
      aa,
      bb,
      cc,
      dd,
      ee,
      ff,
      gg,
      hh
    };

    nk_layout_row_dynamic(ctx, RH / 2, 1);

    nk_label(ctx, "选择运算模式：{四种模式}", NK_TEXT_LEFT);

    if (nk_combo_begin_label(
            ctx, items[selected_item], nk_vec2(nk_widget_width(ctx), RH * 3)))
    {

      nk_layout_row_dynamic(ctx, RH / 2, 1);
      for (int i = 0; i < 4; ++i)

        if (nk_combo_item_symbol_text(
                ctx, gg, items[i], strlen(items[i]), NK_TEXT_RIGHT))
        {
          selected_item = i;
        }

      nk_combo_end(ctx);
    }
    // /silt

    nk_label(ctx, "运算结果：", NK_TEXT_LEFT);
    nk_layout_row_dynamic(ctx, RH * 5, 1);
    nk_flags event110 = nk_edit_string(ctx, NK_EDIT_BOX, box_buffer, &box_len, 1024, nk_filter_float);
    if (event110 & NK_EDIT_ACTIVATED)
    {
      SDL_StartTextInput();
    }
    if (event110 & NK_EDIT_DEACTIVATED)
    {
      SDL_StopTextInput();
    }

    /*    nk_layout_row_dynamic(ctx, RH / 2, 2);
        nk_flags    active = nk_edit_string(ctx, NK_EDIT_FIELD|NK_EDIT_SIG_ENTER, text[7], &text_len[7], 64,  nk_filter_ascii);
        if (active & NK_EDIT_ACTIVATED) { SDL_StartTextInput(); }

        if (active & NK_EDIT_DEACTIVATED) { SDL_StopTextInput(); }
        if (nk_button_label(ctx, "Submit") || (active & NK_EDIT_COMMITED)) {
          SDL_StartTextInput();

          text[7][text_len[7]] = '\n';
          text_len[7]++;
          memcpy(&box_buffer[box_len], &text[7], (nk_size)text_len[7]);
          box_len += text_len[7];
          text_len[7] = 0;
        }*/

    /*  if (nk_tree_push(ctx, NK_TREE_NODE, "List", NK_MINIMIZED))
      {
        static int selected[64] = {nk_false, nk_false, nk_true, nk_false, nk_false, nk_false};

          nk_layout_row_static(ctx, RH/2, 500, 1);

           nk_flags    active = nk_edit_string(ctx, NK_EDIT_FIELD|NK_EDIT_SIG_ENTER, text[7], &text_len[7], 64,  nk_filter_ascii);
if (active & NK_EDIT_ACTIVATED) { SDL_StartTextInput(); }

if (active & NK_EDIT_DEACTIVATED) { SDL_StopTextInput(); }
          nk_selectable_label(ctx, "文本1", NK_TEXT_CENTERED, &selected[0]);
          nk_selectable_label(ctx, "文本2", NK_TEXT_CENTERED, &selected[1]);
          nk_label( ctx, "Not Selectable", NK_TEXT_CENTERED);
          nk_selectable_label(ctx, "Selectable", NK_TEXT_CENTERED, &selected[2]);
          nk_selectable_label(ctx, "Selectable", NK_TEXT_CENTERED, &selected[3]);
          nk_tree_pop(ctx);

      }*/

    /*       {
             static int current_weapon = 0;
             static const char *weapons[] = {
                 "Fist", "Pistol", "Shotgun", "Plasma", "BFG"};

             // default combobox
             nk_layout_row_dynamic(ctx, RH / 4, 1);
             current_weapon = nk_combo(ctx, weapons, NK_LEN(weapons),
                 current_weapon, RH/2, nk_vec2(200, 200));
           }*/

    /* if(  nk_combo_item_symbol_label(
            ctx,gg
 , items[i], NK_TEXT_RIGHT))

    //    if (nk_combo_item_label(ctx, items[i], NK_TEXT_CENTERED))
          selected_item = i;
          */

    static float value = 0.2f;
    /*滚动条*/
    /*nk_layout_row_begin(ctx, NK_STATIC, RH / 2, 2);
    {
            nk_layout_row_push(ctx, 180);
            nk_label(ctx, "调整屏幕亮度:", NK_TEXT_LEFT);
            nk_layout_row_push(ctx, 800);
            nk_slider_float(ctx, 0, &value, 1.0f, 0.1f);
    }*/

    /*函数：文本标签*/
    nk_layout_row_dynamic(ctx, RH / 2, 1);

    /*    nk_layout_row_dynamic(ctx, RH/2, 1);
        nk_label_colored(ctx, buf, NK_TEXT_LEFT, nk_rgb(0, 0, 255));
       // nk_text_wrap(ctx, buf, strlen(buf));
        nk_layout_row_dynamic(ctx, RH/2, 1);
        nk_text_wrap(ctx, buf1, strlen(buf1));
        nk_layout_row_dynamic(ctx, RH/2, 1);
        nk_text_wrap(ctx, buf2, strlen(buf2));
        nk_layout_row_dynamic(ctx, RH/2, 1);
        nk_text_wrap(ctx, buf3, strlen(buf3));
           nk_layout_row_dynamic(ctx, RH/2, 1);
           nk_text_wrap(ctx, buf4, strlen(buf4));*/

    // if (nk_tree_push(ctx, NK_TREE_TAB, "分组", NK_MINIMIZED))
    // static int popup_active;
    // popup
    // nk_layout_row_push(ctx, RH);
    //   nk_layout_row_begin(ctx, NK_STATIC, RH, 2);
    // nk_layout_row_push(ctx, RH);
    // nk_label(ctx, "Popup:", NK_TEXT_LEFT);
    /*nk_layout_row_push(ctx, RH);
    if (nk_button_label(ctx, "关于:"))

    popup_active = 1;
    nk_layout_row_end(ctx);
    if (popup_active) {
            static struct nk_rect s = {280, 600, 500, 70};
            if (nk_popup_begin(ctx, NK_POPUP_STATIC, "Error", 0, s)) {
                    nk_layout_row_dynamic(ctx, RH / 2, 1);
                    nk_label(ctx, "发生了未知错误!!", NK_TEXT_LEFT);
                    nk_layout_row_dynamic(ctx, RH / 3, 2);
                    if (nk_button_label(ctx, "确定")) {
                            popup_active = 0;
                            nk_popup_close(ctx);
                    }
                    if (nk_button_label(ctx, "取消")) {
                      popup_active = 0;
                      nk_popup_close(ctx);
                    }
                    nk_popup_end(ctx);
            } else
              popup_active = nk_false;
    }*/
  }

  nk_end(ctx);
}
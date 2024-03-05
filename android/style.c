
// 定义按钮样式结构体
struct nk_style_button *b_icon;

	/* style for toggle buttons (or select buttons) with image */
	struct nk_style_button b_icon_sel, b_icon_unsel;  // NK图形库按钮样式，用于选中和未选中状态

enum theme {
	THEME_BLACK,   // 黑色主题
	THEME_WHITE,   // 白色主题
	THEME_RED,     // 红色主题
	THEME_BLUE,    // 蓝色主题
	THEME_DARK,    // 深色主题
	THEME_GREEN,   // 绿色主题
	THEME_BROWN,   // 棕色主题
	THEME_PURPLE,  // 紫色主题
	THEME_DRACULA, // Dracula主题
	THEME_DEFAULT  // 默认主题
};

static void
set_style(struct nk_context *ctx, enum theme theme)
{
    struct nk_color table[NK_COLOR_COUNT];
	       if (theme == THEME_BLACK) {
    struct nk_color bg = nk_rgba(20, 20, 25, 255);
    struct nk_color def = nk_rgba(40, 40, 50, 255);
    struct nk_color hv = nk_rgba(40, 40, 50, 255);
    struct nk_color act = nk_rgba(50, 50, 62, 255);
    struct nk_color fg = nk_rgba(200, 200, 200, 255);
    struct nk_color na = nk_rgba(255, 0, 0, 255);

    table[NK_COLOR_TEXT] = fg;
    table[NK_COLOR_WINDOW] = bg;
    table[NK_COLOR_HEADER] = bg;
    table[NK_COLOR_BORDER] = fg;
    table[NK_COLOR_BUTTON] = bg;
    table[NK_COLOR_BUTTON_HOVER] = hv;
    table[NK_COLOR_BUTTON_ACTIVE] = act;
    table[NK_COLOR_TOGGLE] = def;
    table[NK_COLOR_TOGGLE_HOVER] = hv;
    table[NK_COLOR_TOGGLE_CURSOR] = fg;
    table[NK_COLOR_SELECT] = def;
    table[NK_COLOR_SELECT_ACTIVE] = fg;
    table[NK_COLOR_SLIDER] = def;
    table[NK_COLOR_SLIDER_CURSOR] = fg;
    table[NK_COLOR_SLIDER_CURSOR_HOVER] = hv;
    table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = fg;
    table[NK_COLOR_PROPERTY] = fg;
    table[NK_COLOR_EDIT] = bg;
    table[NK_COLOR_EDIT_CURSOR] = fg;
    table[NK_COLOR_COMBO] = na;
    table[NK_COLOR_CHART] = na;
    table[NK_COLOR_CHART_COLOR] = na;
    table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = na;
    table[NK_COLOR_SCROLLBAR] = na;
    table[NK_COLOR_SCROLLBAR_CURSOR] = na;
    table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = na;
    table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = na;
    table[NK_COLOR_TAB_HEADER] = na;
    nk_style_from_table(ctx, table);
    } else if (theme == THEME_WHITE) {
		table[NK_COLOR_TEXT] = nk_rgba(35, 35, 35, 255);
		table[NK_COLOR_WINDOW] = nk_rgba(225, 225, 225, 255);
		table[NK_COLOR_HEADER] = nk_rgba(175, 175, 175, 255);
		table[NK_COLOR_BORDER] = nk_rgba(0, 0, 0, 255);
		table[NK_COLOR_BUTTON] = nk_rgba(200, 200, 200, 255);
		table[NK_COLOR_BUTTON_HOVER] = nk_rgba(170, 170, 170, 255);
		table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(160, 160, 160, 255);
		table[NK_COLOR_TOGGLE] = nk_rgba(150, 150, 150, 255);
		table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(120, 120, 120, 255);
		table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(225, 225, 225, 255);
		table[NK_COLOR_SELECT] = nk_rgba(200, 200, 200, 255);
		table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(225, 225, 225, 255);
		table[NK_COLOR_SLIDER] = nk_rgba(200, 200, 200, 255);
		table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(80, 80, 80, 255);
		table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(70, 70, 70, 255);
		table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(60, 60, 60, 255);
		table[NK_COLOR_PROPERTY] = nk_rgba(225, 225, 225, 255);
		table[NK_COLOR_EDIT] = nk_rgba(175, 175, 175, 255);
		table[NK_COLOR_EDIT_CURSOR] = nk_rgba(0, 0, 0, 255);
		table[NK_COLOR_COMBO] = nk_rgba(225, 225, 225, 255);
		table[NK_COLOR_CHART] = nk_rgba(160, 160, 160, 255);
		table[NK_COLOR_CHART_COLOR] = nk_rgba(45, 45, 45, 255);
		table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba( 255, 0, 0, 255);
		table[NK_COLOR_SCROLLBAR] = nk_rgba(180, 180, 180, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(140, 140, 140, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(150, 150, 150, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(160, 160, 160, 255);
		table[NK_COLOR_TAB_HEADER] = nk_rgba(180, 180, 180, 255);
		nk_style_from_table(ctx, table);
	} else if (theme == THEME_RED) {
		table[NK_COLOR_TEXT] = nk_rgba(190, 190, 190, 255);
		table[NK_COLOR_WINDOW] = nk_rgba(30, 33, 40, 215);
		table[NK_COLOR_HEADER] = nk_rgba(181, 45, 69, 220);
		table[NK_COLOR_BORDER] = nk_rgba(51, 55, 67, 255);
		table[NK_COLOR_BUTTON] = nk_rgba(181, 45, 69, 255);
		table[NK_COLOR_BUTTON_HOVER] = nk_rgba(190, 50, 70, 255);
		table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(195, 55, 75, 255);
		table[NK_COLOR_TOGGLE] = nk_rgba(51, 55, 67, 255);
		table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(45, 60, 60, 255);
		table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(181, 45, 69, 255);
		table[NK_COLOR_SELECT] = nk_rgba(51, 55, 67, 255);
		table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(181, 45, 69, 255);
		table[NK_COLOR_SLIDER] = nk_rgba(51, 55, 67, 255);
		table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(181, 45, 69, 255);
		table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(186, 50, 74, 255);
		table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(191, 55, 79, 255);
		table[NK_COLOR_PROPERTY] = nk_rgba(51, 55, 67, 255);
		table[NK_COLOR_EDIT] = nk_rgba(51, 55, 67, 225);
		table[NK_COLOR_EDIT_CURSOR] = nk_rgba(190, 190, 190, 255);
		table[NK_COLOR_COMBO] = nk_rgba(51, 55, 67, 255);
		table[NK_COLOR_CHART] = nk_rgba(51, 55, 67, 255);
		table[NK_COLOR_CHART_COLOR] = nk_rgba(170, 40, 60, 255);
		table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba( 255, 0, 0, 255);
		table[NK_COLOR_SCROLLBAR] = nk_rgba(30, 33, 40, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(64, 84, 95, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(70, 90, 100, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(75, 95, 105, 255);
		table[NK_COLOR_TAB_HEADER] = nk_rgba(181, 45, 69, 220);
		nk_style_from_table(ctx, table);
	} else if (theme == THEME_BLUE) {
        table[NK_COLOR_TEXT] = nk_rgba(20, 20, 20, 255);
        table[NK_COLOR_WINDOW] = nk_rgba(202, 212, 214, 215);
        table[NK_COLOR_HEADER] = nk_rgba(137, 182, 224, 220);
        table[NK_COLOR_BORDER] = nk_rgba(140, 159, 173, 255);
        table[NK_COLOR_BUTTON] = nk_rgba(137, 182, 224, 255);
        table[NK_COLOR_BUTTON_HOVER] = nk_rgba(142, 187, 229, 255);
        table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(147, 192, 234, 255);
        table[NK_COLOR_TOGGLE] = nk_rgba(177, 210, 210, 255);
        table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(182, 215, 215, 255);
        table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(137, 182, 224, 255);
        table[NK_COLOR_SELECT] = nk_rgba(177, 210, 210, 255);
        table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(137, 182, 224, 255);
        table[NK_COLOR_SLIDER] = nk_rgba(177, 210, 210, 255);
        table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(137, 182, 224, 245);
        table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(142, 188, 229, 255);
        table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(147, 193, 234, 255);
        table[NK_COLOR_PROPERTY] = nk_rgba(210, 210, 210, 255);
        table[NK_COLOR_EDIT] = nk_rgba(210, 210, 210, 225);
        table[NK_COLOR_EDIT_CURSOR] = nk_rgba(20, 20, 20, 255);
        table[NK_COLOR_COMBO] = nk_rgba(210, 210, 210, 255);
        table[NK_COLOR_CHART] = nk_rgba(210, 210, 210, 255);
        table[NK_COLOR_CHART_COLOR] = nk_rgba(137, 182, 224, 255);
        table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba( 255, 0, 0, 255);
        table[NK_COLOR_SCROLLBAR] = nk_rgba(190, 200, 200, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(64, 84, 95, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(70, 90, 100, 255);
        table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(75, 95, 105, 255);
        table[NK_COLOR_TAB_HEADER] = nk_rgba(156, 193, 220, 255);
        nk_style_from_table(ctx, table);
	} else if (theme == THEME_DARK) {
		table[NK_COLOR_TEXT] = nk_rgba(210, 210, 210, 255);
		table[NK_COLOR_WINDOW] = nk_rgba(57, 67, 71, 215);
		table[NK_COLOR_HEADER] = nk_rgba(51, 51, 56, 220);
		table[NK_COLOR_BORDER] = nk_rgba(46, 46, 46, 255);
		table[NK_COLOR_BUTTON] = nk_rgba(48, 83, 111, 255);
		table[NK_COLOR_BUTTON_HOVER] = nk_rgba(58, 93, 121, 255);
		table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(63, 98, 126, 255);
		table[NK_COLOR_TOGGLE] = nk_rgba(50, 58, 61, 255);
		table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(45, 53, 56, 255);
		table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(48, 83, 111, 255);
		table[NK_COLOR_SELECT] = nk_rgba(57, 67, 61, 255);
		table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(48, 83, 111, 255);
		table[NK_COLOR_SLIDER] = nk_rgba(50, 58, 61, 255);
		table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(48, 83, 111, 245);
		table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(53, 88, 116, 255);
		table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(58, 93, 121, 255);
		table[NK_COLOR_PROPERTY] = nk_rgba(50, 58, 61, 255);
		table[NK_COLOR_EDIT] = nk_rgba(50, 58, 61, 225);
		table[NK_COLOR_EDIT_CURSOR] = nk_rgba(210, 210, 210, 255);
		table[NK_COLOR_COMBO] = nk_rgba(50, 58, 61, 255);
		table[NK_COLOR_CHART] = nk_rgba(50, 58, 61, 255);
		table[NK_COLOR_CHART_COLOR] = nk_rgba(48, 83, 111, 255);
		table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba(255, 0, 0, 255);
		table[NK_COLOR_SCROLLBAR] = nk_rgba(50, 58, 61, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(48, 83, 111, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(53, 88, 116, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(58, 93, 121, 255);
		table[NK_COLOR_TAB_HEADER] = nk_rgba(48, 83, 111, 255);
		nk_style_from_table(ctx, table);
	} else if (theme == THEME_GREEN) {
		table[NK_COLOR_TEXT] = nk_rgba(244, 244, 244, 255);
		table[NK_COLOR_WINDOW] = nk_rgba(57, 71, 58, 215);
		table[NK_COLOR_HEADER] = nk_rgba(52, 57, 52, 220);
		table[NK_COLOR_BORDER] = nk_rgba(46, 46, 46, 255);
		table[NK_COLOR_BUTTON] = nk_rgba(48, 112, 54, 255);
		table[NK_COLOR_BUTTON_HOVER] = nk_rgba(71, 161, 80, 255);
		table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(89, 201, 100, 255);
		table[NK_COLOR_TOGGLE] = nk_rgba(50, 61, 50, 255);
		table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(73, 84, 72, 255);
		table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(48, 112, 54, 255);
		table[NK_COLOR_SELECT] = nk_rgba(58, 67, 57, 255);
		table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(48, 112, 54, 255);
		table[NK_COLOR_SLIDER] = nk_rgba(50, 61, 50, 255);
		table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(48, 112, 54, 245);
		table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(59, 115, 53, 255);
		table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(71, 161, 80, 255);
		table[NK_COLOR_PROPERTY] = nk_rgba(50, 61, 50, 255);
		table[NK_COLOR_EDIT] = nk_rgba(50, 61, 50, 225);
		table[NK_COLOR_EDIT_CURSOR] = nk_rgba(210, 210, 210, 255);
		table[NK_COLOR_COMBO] = nk_rgba(50, 61, 50, 255);
		table[NK_COLOR_CHART] = nk_rgba(50, 61, 50, 255);
		table[NK_COLOR_CHART_COLOR] = nk_rgba(48, 112, 54, 255);
		table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba(255, 0, 0, 255);
		table[NK_COLOR_SCROLLBAR] = nk_rgba(50, 61, 50, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(48, 112, 54, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(59, 115, 53, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(71, 161, 80, 255);
		table[NK_COLOR_TAB_HEADER] = nk_rgba(48, 112, 54, 255);
		nk_style_from_table(ctx, table);
	} else if (theme == THEME_BROWN) {
		table[NK_COLOR_TEXT] = nk_rgba(210, 210, 210, 255);
		table[NK_COLOR_WINDOW] = nk_rgba(71, 67, 57, 215);
		table[NK_COLOR_HEADER] = nk_rgba(56, 51, 51, 220);
		table[NK_COLOR_BORDER] = nk_rgba(46, 46, 46, 255);
		table[NK_COLOR_BUTTON] = nk_rgba(111, 83, 48, 255);
		table[NK_COLOR_BUTTON_HOVER] = nk_rgba(121, 93, 58, 255);
		table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(126, 98, 63, 255);
		table[NK_COLOR_TOGGLE] = nk_rgba(61, 58, 50, 255);
		table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(56, 53, 45, 255);
		table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(111, 83, 48, 255);
		table[NK_COLOR_SELECT] = nk_rgba(61, 67, 57, 255);
		table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(111, 83, 48, 255);
		table[NK_COLOR_SLIDER] = nk_rgba(61, 58, 50, 255);
		table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(111, 83, 48, 245);
		table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(116, 88, 53, 255);
		table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(121, 93, 58, 255);
		table[NK_COLOR_PROPERTY] = nk_rgba(61, 58, 50, 255);
		table[NK_COLOR_EDIT] = nk_rgba(61, 58, 50, 225);
		table[NK_COLOR_EDIT_CURSOR] = nk_rgba(210, 210, 210, 255);
		table[NK_COLOR_COMBO] = nk_rgba(61, 58, 50, 255);
		table[NK_COLOR_CHART] = nk_rgba(61, 58, 50, 255);
		table[NK_COLOR_CHART_COLOR] = nk_rgba(111, 83, 48, 255);
		table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba(0, 0, 255, 255);
		table[NK_COLOR_SCROLLBAR] = nk_rgba(61, 58, 50, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(111, 83, 48, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(116, 88, 53, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(121, 93, 58, 255);
		table[NK_COLOR_TAB_HEADER] = nk_rgba(111, 83, 48, 255);
		nk_style_from_table(ctx, table);
	} else if (theme == THEME_PURPLE) {
		table[NK_COLOR_TEXT] = nk_rgba(210, 210, 210, 255);
		table[NK_COLOR_WINDOW] = nk_rgba(67, 57, 71, 215);
		table[NK_COLOR_HEADER] = nk_rgba(51, 51, 56, 220);
		table[NK_COLOR_BORDER] = nk_rgba(46, 46, 46, 255);
		table[NK_COLOR_BUTTON] = nk_rgba(83, 48, 111, 255);
		table[NK_COLOR_BUTTON_HOVER] = nk_rgba(93, 58, 121, 255);
		table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(98, 63, 126, 255);
		table[NK_COLOR_TOGGLE] = nk_rgba(58, 50, 61, 255);
		table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(53, 45, 56, 255);
		table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(83, 48, 111, 255);
		table[NK_COLOR_SELECT] = nk_rgba(67, 57, 61, 255);
		table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(83, 48, 111, 255);
		table[NK_COLOR_SLIDER] = nk_rgba(58, 50, 61, 255);
		table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(83, 48, 111, 245);
		table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(88, 53, 116, 255);
		table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(93, 58, 121, 255);
		table[NK_COLOR_PROPERTY] = nk_rgba(58, 50, 61, 255);
		table[NK_COLOR_EDIT] = nk_rgba(58, 50, 61, 225);
		table[NK_COLOR_EDIT_CURSOR] = nk_rgba(210, 210, 210, 255);
		table[NK_COLOR_COMBO] = nk_rgba(58, 50, 61, 255);
		table[NK_COLOR_CHART] = nk_rgba(58, 50, 61, 255);
		table[NK_COLOR_CHART_COLOR] = nk_rgba(83, 48, 111, 255);
		table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba(0, 255, 0, 255);
		table[NK_COLOR_SCROLLBAR] = nk_rgba(58, 50, 61, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(83, 48, 111, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(88, 53, 116, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(93, 58, 121, 255);
		table[NK_COLOR_TAB_HEADER] = nk_rgba(83, 48, 111, 255);
		nk_style_from_table(ctx, table);
	} else if (theme == THEME_DRACULA) {
		table[NK_COLOR_TEXT] = nk_rgba(248, 248, 242, 255);//文本
		table[NK_COLOR_WINDOW] = nk_rgba(68, 71, 90, 255);//窗口
		table[NK_COLOR_HEADER] = nk_rgba(40, 42, 54, 255);//标题栏颜色
		table[NK_COLOR_BORDER] = nk_rgba(0, 0, 0, 255);//边框颜色
		table[NK_COLOR_BUTTON] = nk_rgba(98, 114, 164, 255);//按钮颜色
		table[NK_COLOR_BUTTON_HOVER] = nk_rgba(255, 121, 198, 255);//鼠标悬停时按钮颜色
		table[NK_COLOR_BUTTON_ACTIVE] = nk_rgba(255, 85, 85, 255);//按钮按下时颜色
		table[NK_COLOR_TOGGLE] = nk_rgba(40, 42, 54, 255);//切换按钮颜色
		table[NK_COLOR_TOGGLE_HOVER] = nk_rgba(255, 121, 198, 255);//鼠标悬停时切换按钮颜色
		table[NK_COLOR_TOGGLE_CURSOR] = nk_rgba(255, 85, 85, 255);//切换按钮光标颜色
		table[NK_COLOR_SELECT] = nk_rgba(98, 114, 164, 255);//选择颜色
		table[NK_COLOR_SELECT_ACTIVE] = nk_rgba(255, 85, 85, 255);//活动选择颜色
		table[NK_COLOR_SLIDER] = nk_rgba(40, 42, 54, 255);//滑块颜色
		table[NK_COLOR_SLIDER_CURSOR] = nk_rgba(98, 114, 164, 255);//滑块光标颜色
		table[NK_COLOR_SLIDER_CURSOR_HOVER] = nk_rgba(255, 121, 198, 255);//鼠标悬停时滑块光标颜色
		table[NK_COLOR_SLIDER_CURSOR_ACTIVE] = nk_rgba(255, 85, 85, 255);//滑块光标按下时颜色
		table[NK_COLOR_PROPERTY] = nk_rgba(40, 42, 54, 255);//属性颜色
		table[NK_COLOR_EDIT] = nk_rgba(40, 42, 54, 255);//编辑框颜色
		table[NK_COLOR_EDIT_CURSOR] = nk_rgba(255, 184, 108, 255);//编辑框光标颜色
		table[NK_COLOR_COMBO] = nk_rgba(40, 42, 54, 255);//组合框颜色
		table[NK_COLOR_CHART] = nk_rgba(40, 42, 54, 255);//图表颜色
		table[NK_COLOR_CHART_COLOR] = nk_rgba(68, 71, 90, 255);//图表线颜色
		table[NK_COLOR_CHART_COLOR_HIGHLIGHT] = nk_rgba(255, 184, 108, 255);//图表线高亮颜色
		//table[NK_COLOR_SCROLLBAR] = nk_rgba(40, 42, 54, 255);//滚动条颜色
		table[NK_COLOR_SCROLLBAR] = nk_rgba(58, 50, 61, 255);
		table[NK_COLOR_SCROLLBAR_CURSOR] = nk_rgba(98, 114, 164, 255);//滚动条光标颜色
		table[NK_COLOR_SCROLLBAR_CURSOR_HOVER] = nk_rgba(255, 121, 198, 255);//鼠标悬停时滚动条光标颜色
		table[NK_COLOR_SCROLLBAR_CURSOR_ACTIVE] = nk_rgba(255, 85, 85, 255);//滚动条光标按下时颜色
		table[NK_COLOR_TAB_HEADER] = nk_rgba(255, 85, 85, 255);//选项卡标题颜色

    nk_style_from_table(ctx, table);
}
 else {
        nk_style_default(ctx);
    }

}





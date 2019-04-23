# oop-GraphEditor

## A
- 图形界面（包含每个工具的UI）
- **程序基本框架(图形、元素的数据结构，鼠标键盘相关函数)**

## B
- 图片文件的读取及保存（打开格式支持jpg，png，bmp等，保存时支持格式格式转化）(支持压缩图片)
- **图层功能的实现**（图层能够拖动），保存时生成特殊格式（如PS里的.psd，用于保存图层，图形对象等原始信息）

## C
- 画笔自由绘制**工具**（画笔支持.bar文件导入）（支持画笔大小、颜色调节）
- 取色器，调色盘**工具**（绘制图形的默认颜色为取色器当前选择颜色，即前景色）
- 橡皮擦**工具**（不同图层上都可以实现擦除）

## D
- 图形生成**工具**（在所选图层上二维绘制直线，圆，多边形，贝塞尔曲线）（线条粗细、颜色可调）
- 锚点选择修改**工具**（选择绘制直线、多边形的顶点，实现自由拖动，改变图形形状）（支持添加／删除锚点）

## E
- 填充**工具**（计算闭合曲线范围，填充颜色）
- 文字**工具**（字体支持主流字体格式.ttf导入）（颜色，大小，是否加粗可调）
- 图片裁剪工具

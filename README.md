# oop-GraphEditor

<代码请见:editor1.1 branch>

## 一、基本思路

- 图层 (File Layer::Class Slice)包含RGB三个一维数组，主图层(File Layer::Class MyLayer)中的updateImage()函数根据混合模式，不透明度，可见性等参数得出叠加后的结果储存于imageRGB中，view(File view::Class Myview)中的updateItem()函数负责将合成imageRGB显示出来
- 用户在图层面板区选择不同图层时，pLayer->focus会发生改变，即当前选择图层的焦点会改变
- 各种工具在当前选中图层上进行操作时，可以新建一个临时图层，修改完成后，再依次调用pLayer->updateimage()更新内部数据结构,调用pView->updateItem()在显示区更新结果


## 二、文件说明

- file.h中包含文件方法: 1.新建文件 2.打开文件(未实现) 3.保存文件(未实现)

- layer.h包含图层处理方法 1.添加图层 2.删除图层

- view.h包含图层显示方法 1.缩放图层 2.获取某个图层数据数组二维坐标 3.移动图层

- mainwindow.h主要包含各按钮的响应函数，以及主界面图形和位置的初始化

注意事项:目前图层数最多为11个



## 三、主要操作

### 1.修改图层

- (未实现)

#### Sample

```C++

```

### 2.添加图层

#### Sample

```C++

```

### 3.删除图层

#### Sample

```C++

```

## 四、具体分工(有更新)

<每人部分可以先做个简单ui，后期来优化>

- A：朱

    1.图形界面的优化(包含每个工具UI的优化)
    2.图片文件的读取及保存(打开格式支持jpg，png，bmp，保存时支持格式格式转化)(支持压缩图片)(不包括保存为.psd特殊格式的功能)

- B：程

    1.程序基本框架(图层数据结构，鼠标键盘相关响应函数)
    2.图层功能的实现（图层合成，图层拖动，放大缩小），保存时生成特殊格式（如PS里的.psd，用于保存图层，图形对象等原始信息）
    3.滤镜效果

- C：赵

    1.画笔自由绘制工具(画笔支持.bar文件导入?)(支持画笔大小、颜色调节)
    2.取色器，调色盘工具(绘制图形的默认颜色为取色器当前选择颜色，即前景色)
    3.橡皮擦工具(不同图层上都可以实现擦除)

- D：覃

    1.图形生成工具(在所选图层上二维绘制直线，圆，多边形，贝塞尔曲线)(线条粗细、颜色可调)(大小位置可通过参数面板调节)
    2.锚点选择修改工具(选择绘制直线、多边形的顶点，实现自由拖动，改变图形形状)(支持添加／删除锚点)
    

- E：仇

    1.填充工具(计算闭合曲线范围，填充颜色)
    2.文字工具(字体支持主流字体格式.ttf导入)(颜色，大小，是否加粗，下划线可调)
    3.图片裁剪工具
    
    
- Supplement：
    1.钢笔工具(可以通过闭合曲线来获取选区，和锚点工具可配合使用)，矩形，圆形选区工具
    
    
### 时间表



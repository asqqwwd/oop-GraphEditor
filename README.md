# oop-GraphEditor <代码请见:editor1.1 branch>

一、说明

file.h中包含文件方法: 1.新建文件 2.打开文件(未实现) 3.保存文件(未实现)

layer.h包含图层处理方法 1.添加图层 2.删除图层

view.h包含图层显示方法 1.缩放图层 2.获取某个图层数据数组二维坐标 3.移动图层

mainwindown.h主要包含各按钮的响应函数，以及主界面图形和位置的初始化

注意事项:目前图层数最多为11个



二、更新

2019-5-24更新:

  1.修复了图层可视按钮bug
  
  2.view.h里的press_point和release_point坐标从scene坐标变为图层数据数组二维坐标
  
  3.现在拖动图片改变位置时，鼠标移出界面外后，拖动将会停止
  

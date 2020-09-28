/*
  Name: 拓扑排序 
  CopyRight:
  Author: Cz
  Date: 2019/8/27 22:05:02
  Description:
  方法1： 维护各顶点的入度，in[V],  把入度为0的点入栈,只要栈不空，将栈顶元素u弹出，加入结果集合S，
  并将u的所有直接相连的v的入度减一，再次将入度为0的点入栈。最后如果结果集合的大小等于V则成功，否则失败 
  方法二：先判断图中是否有环，如果没有取图G的逆后序遍历序列 
*/




//取整的时候一定要乘以一个浮点数！！！！！！！！！！！！！！！！！！！！！！！！！！！！

//下取整转换为上取整
// ceil(a/b) == floor(a+b-1/ b) 

//下取整
int floor(double x)
{
    return (int) x - (x<0);
}
 
//上取整
int ceil(double x)
{
    return (int) x + (x>0);
}
 
//四舍五入
int round(double x)
{
    return floor(x+0.5);
}

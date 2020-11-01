# stm32-lwip

### 说明

* 没有按照 正点原子 教程中修改icmp.c文件中**硬件帧校验**的代码
* 没有使用片外flash。（因此，不需要修改mem.c中的ram_heap；memp.c中的memp_memory）
    * lwip2.1与1.4的内存池与内存堆的不同：
    * lwip2.1中没有memp_memory数组，改为memp = (struct memp *)LWIP_MEM_ALIGN(desc->base);
    * lwip2.1中内存堆与内存池的定义方式也不太相同
    * ![00-内存池与内存堆](00-picture/00-内存池与内存堆.png)












#include "address_space.h"


/*
Finds a the page containing the data at bs_off.
*/

struct page* find_page_file(struct file* f, int bs_off){
  struct address_space* mapping = f->f_mapping;
  struct xarray i_pages = mapping -> i_pages;
  int pg_off = bs_off/4096; //integer division to get offset into pages
  struct page* page_ptr = xa_load(&i_pages, pg_off);
  if(!page_ptr){
    printk("It didn't work\n");
  }else{
    printk("It worked!\n");
  }

  return page_ptr;
}
struct page* find_page_inode(struct inode* i, int bs_off){
  struct address_space* mapping = i->i_mapping;
  struct xarray i_pages = mapping -> i_pages;
  int pg_off = bs_off/4096; //integer division to get offset into pages
  struct page* page_ptr = xa_load(&i_pages, pg_off);
  if(!page_ptr){
    printk("It didn't work\n");
  }else{
    printk("It worked!\n");
  }

  return page_ptr;
}


/*
Make this use buffers instead of using something on the stack cause thats cringe. 
*/
void get_all_pages_inode(struct inode* i, const loff_t size, struct page** buf){
  int inc;
  struct address_space* mapping = i->i_mapping;
  struct xarray i_pages = mapping -> i_pages;
  struct page* ret_arr[size%4096]; //declare array of size size
  for(inc = 0; inc<size%4096; inc++){
    ret_arr[inc]= xa_load(&i_pages, inc);

  }
}


/*
Force writeback of num_pages from the page cache of inode
*/

int force_writeback(struct inode* inode, int num_pages){
  struct writeback_control wb;
  int ret;
  wb.nr_to_write = num_pages;
  ret = generic_writepages(inode->i_mapping, &wb);
  printk("%d %ld\n", ret, wb.nr_to_write);
  return ret;
}

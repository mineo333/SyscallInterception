cmd_/home/mineo333/SyscallInterception/Module.symvers := sed 's/ko$$/o/' /home/mineo333/SyscallInterception/modules.order | scripts/mod/modpost -m -a   -o /home/mineo333/SyscallInterception/Module.symvers -e -i Module.symvers   -T -

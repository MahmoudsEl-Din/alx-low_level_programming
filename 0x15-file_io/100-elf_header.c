#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_header(Elf64_Ehdr *hdr) {
    printf("ELF Header:\n");
    printf("  Magic:   %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
           hdr->e_ident[EI_MAG0], hdr->e_ident[EI_MAG1], hdr->e_ident[EI_MAG2], hdr->e_ident[EI_MAG3],
           hdr->e_ident[EI_MAG4], hdr->e_ident[EI_MAG5], hdr->e_ident[EI_MAG6], hdr->e_ident[EI_MAG7],
           hdr->e_ident[EI_MAG8], hdr->e_ident[EI_MAG9], hdr->e_ident[EI_MAG10], hdr->e_ident[EI_MAG11],
           hdr->e_ident[EI_MAG12], hdr->e_ident[EI_MAG13], hdr->e_ident[EI_MAG14], hdr->e_ident[EI_MAG15]);
    printf("  Class:                             %s\n", hdr->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", hdr->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
    printf("  Version:                           %d (current)\n", hdr->e_ident[EI_VERSION]);
    printf("  OS/ABI:                            ");
    switch (hdr->e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
        case ELFOSABI_HPUX: printf("UNIX - HP-UX\n"); break;
        case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
        case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
        case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
        case ELFOSABI_AIX: printf("UNIX - AIX\n"); break;
        case ELFOSABI_IRIX: printf("UNIX - IRIX\n"); break;
        case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
        case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
        case ELFOSABI_MODESTO: printf("Novell - Modesto\n"); break;
        case ELFOSABI_OPENBSD: printf("UNIX - OpenBSD\n"); break;
        case ELFOSABI_OPENVMS: printf("VMS - OpenVMS\n"); break;
        case ELFOSABI_NSK: printf("HP - Non-Stop Kernel\n"); break;
        case ELFOSABI_AROS: printf("AROS\n"); break;
        default: printf("<unknown: %d>\n", hdr->e_ident[EI_OSABI]); break;
    }
    printf("  ABI Version:                       %d\n", hdr->e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (hdr->e_type) {
        case ET_NONE: printf("NONE (No file type)\n"); break;
        case ET_REL: printf("REL (Relocatable file)\n"); break;
        case ET_EXEC: printf("EXEC (Executable file)\n"); break;
        case ET_DYN: printf("DYN (Shared object file)\n"); break;
        case ET_CORE: printf("CORE (Core file)\n"); break;
        default: printf("<unknown: %d>\n", hdr->e_type); break;
    }
    printf("  Entry point address:               0x%lx\n", (unsigned long)hdr->e_entry);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: could not open file %s\n", argv[1]);
        exit(98);
    }

    Elf64_Ehdr hdr;
    if (read(fd, &hdr, sizeof(hdr)) != sizeof(hdr)) {
        fprintf(stderr, "Error: could not read ELF header from file %s\n", argv[1]);
        exit(98);
    }

    if (hdr.e_ident[EI_MAG0] != ELFMAG0 || hdr.e_ident[EI_MAG1] != ELFMAG1 || hdr.e_ident[EI_MAG2] != ELFMAG2 || hdr.e_ident[EI_MAG3] != ELFMAG3) {
        fprintf(stderr, "Error: file %s is not an ELF file\n", argv[1]);
        exit(98);
    }

    print_header(&hdr);

    close(fd);
    return 0;
}

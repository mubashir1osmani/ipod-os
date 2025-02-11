const BOOTLOADER_ORG = 0x7C00;
const BOOTLOADER_STACK = 0x7C00;

export fn _start() callconv(.Naked) noreturn {
    // Set up segments
    asm volatile (
        \\  xor ax, ax
        \\  mov ds, ax
        \\  mov es, ax
        \\  mov ss, ax
        \\  mov sp, %[stack]
        :
        : [stack] "n" (BOOTLOADER_STACK)
    );

    // Print welcome message
    print("iPodOS Bootloader v0.1\r\n");
    
    // Halt the system
    while (true) {
        asm volatile ("hlt");
    }
}

fn print(msg: []const u8) void {
    for (msg) |c| {
        printChar(c);
    }
}

fn printChar(c: u8) void {
    asm volatile (
        \\  mov ah, 0x0E
        \\  mov al, %[char]
        \\  int 0x10
        :
        : [char] "r" (c)
        : "ax"
    );
}

// Magic boot sector signature
export var magic: u16 align(1) linksection(".magic") = 0xAA55;

comptime {
    // Ensure our code fits in the boot sector (512 bytes)
    @export(_start, .{ .name = "_start", .section = ".text" });
    asm (
        \\.section .text
        \\.org 0x7C00
    );
}

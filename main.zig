const std = @import("std");

const config = @import("config");

pub fn main() !void {
    _ = try std.heap.page_allocator.init(std.heap.BlockAllocatorInit);
    defer std.heap.page_allocator.deinit();

    // Initialize our OS configuration
    try config.init();

    // Main loop
    while (true) {
        // Handle user input or other events here
    }
}

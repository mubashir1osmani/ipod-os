const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    // Default to 'dev' step when no specific step is specified
    const dev_step = b.step("dev", "Build development target");
    b.default_step = dev_step;

    // Executable configuration
    const exe = b.addExecutable(.{
        .name = "os",
        .root_source_file = .{ .path = "main.zig" },
        .target = target,
        .optimize = optimize,
    });

    // Build steps
    const build_step = b.step("build", "Build the project");
    build_step.dependOn(&exe.step);

    const release_step = b.step("release", "Build release version");
    exe.optimize = .ReleaseFast;
    release_step.dependOn(&exe.step);
}

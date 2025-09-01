.PHONY: clean distclean

BUILD_DIR ?= build

clean:
	@if [ -d "$(BUILD_DIR)" ]; then \
		echo "Cleaning build dir: $(BUILD_DIR)"; \
		meson compile -C $(BUILD_DIR) --clean 2>/dev/null || ninja -C $(BUILD_DIR) clean; \
	else \
		echo "No build dir to clean: $(BUILD_DIR)"; \
	fi

distclean: clean
	@echo "Removing build dir and profiler outputs"
	@rm -rf "$(BUILD_DIR)"
	@rm -f callgrind.* massif.* vgcore.* gmon.out perf.data*

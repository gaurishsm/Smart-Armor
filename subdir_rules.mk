################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
CC2650_LAUNCHXL.obj: ../CC2650_LAUNCHXL.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/gauri/Desktop/empty_CC2650_LAUNCHXL_TI_CC2650F128" --include_path="C:/Users/gauri/Desktop/empty_CC2650_LAUNCHXL_TI_CC2650F128" --include_path="C:/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/cc26xxware_2_24_03_17272" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="CC2650_LAUNCHXL.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

ccfg.obj: ../ccfg.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/gauri/Desktop/empty_CC2650_LAUNCHXL_TI_CC2650F128" --include_path="C:/Users/gauri/Desktop/empty_CC2650_LAUNCHXL_TI_CC2650F128" --include_path="C:/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/cc26xxware_2_24_03_17272" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="ccfg.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

empty.obj: ../empty.c $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/bin/armcl" -mv7M3 --code_state=16 --float_support=vfplib -me --include_path="C:/Users/gauri/Desktop/empty_CC2650_LAUNCHXL_TI_CC2650F128" --include_path="C:/Users/gauri/Desktop/empty_CC2650_LAUNCHXL_TI_CC2650F128" --include_path="C:/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/cc26xxware_2_24_03_17272" --include_path="C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="empty.d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

build-1907601857:
	@$(MAKE) --no-print-directory -Onone -f subdir_rules.mk build-1907601857-inproc

build-1907601857-inproc: ../empty.cfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: XDCtools'
	"C:/ti/xdctools_3_32_02_25_core/xs" --xdcpath="C:/ti/tirtos_cc13xx_cc26xx_2_21_00_06/packages;C:/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/tidrivers_cc13xx_cc26xx_2_21_00_04/packages;C:/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/bios_6_46_01_37/packages;C:/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/uia_2_01_00_01/packages;" xdc.tools.configuro -o configPkg -t ti.targets.arm.elf.M3 -p ti.platforms.simplelink:CC2650F128 -r release -c "C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS" --compileOptions "-mv7M3 --code_state=16 --float_support=vfplib -me --include_path=\"C:/Users/gauri/Desktop/empty_CC2650_LAUNCHXL_TI_CC2650F128\" --include_path=\"C:/Users/gauri/Desktop/empty_CC2650_LAUNCHXL_TI_CC2650F128\" --include_path=\"C:/ti/tirtos_cc13xx_cc26xx_2_21_00_06/products/cc26xxware_2_24_03_17272\" --include_path=\"C:/ti/ccsv8/tools/compiler/ti-cgt-arm_18.1.2.LTS/include\" --define=ccs -g --diag_warning=225 --diag_warning=255 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi  " "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

configPkg/linker.cmd: build-1907601857 ../empty.cfg
configPkg/compiler.opt: build-1907601857
configPkg/: build-1907601857



  //Example instantiation for system 'kernel'
  kernel kernel_inst
    (
      .bidir_port_to_and_from_the_usb_db (bidir_port_to_and_from_the_usb_db),
      .clk                               (clk),
      .data0_to_the_epcs                 (data0_to_the_epcs),
      .dclk_from_the_epcs                (dclk_from_the_epcs),
      .in_port_to_the_usb_nint           (in_port_to_the_usb_nint),
      .out_port_from_the_led             (out_port_from_the_led),
      .out_port_from_the_usb_a0          (out_port_from_the_usb_a0),
      .out_port_from_the_usb_rd          (out_port_from_the_usb_rd),
      .out_port_from_the_usb_wr          (out_port_from_the_usb_wr),
      .reset_n                           (reset_n),
      .sce_from_the_epcs                 (sce_from_the_epcs),
      .sdo_from_the_epcs                 (sdo_from_the_epcs),
      .zs_addr_from_the_sdram            (zs_addr_from_the_sdram),
      .zs_ba_from_the_sdram              (zs_ba_from_the_sdram),
      .zs_cas_n_from_the_sdram           (zs_cas_n_from_the_sdram),
      .zs_cke_from_the_sdram             (zs_cke_from_the_sdram),
      .zs_cs_n_from_the_sdram            (zs_cs_n_from_the_sdram),
      .zs_dq_to_and_from_the_sdram       (zs_dq_to_and_from_the_sdram),
      .zs_dqm_from_the_sdram             (zs_dqm_from_the_sdram),
      .zs_ras_n_from_the_sdram           (zs_ras_n_from_the_sdram),
      .zs_we_n_from_the_sdram            (zs_we_n_from_the_sdram)
    );


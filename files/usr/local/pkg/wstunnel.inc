<?php
/*
 * wstunnel.inc
 * BSD 3-Clause License                                                             
 *                                                                                  
 * Copyright (c) 2024 Siddhant Kameswar
 *                                                                                  
 * Redistribution and use in source and binary forms, with or without               
 * modification, are permitted provided that the following conditions are met:      
 *                                                                                  
 * 1. Redistributions of source code must retain the above copyright notice, this   
 *    list of conditions and the following disclaimer.                              
 *                                                                                  
 * 2. Redistributions in binary form must reproduce the above copyright notice,     
 *    this list of conditions and the following disclaimer in the documentation     
 *    and/or other materials provided with the distribution.                        
 *                                                                                  
 * 3. Neither the name of the copyright holder nor the names of its                 
 *    contributors may be used to endorse or promote products derived from          
 *    this software without specific prior written permission.                      
 *                                                                                  
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"      
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE        
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE   
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE     
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL       
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR       
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER       
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,    
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE    
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

require_once("certs.inc");
require_once("config.inc");
require_once("pfsense-utils.inc");
require_once("util.inc");
require_once("services.inc");
require_once("service-utils.inc");
require_once("xmlrpc_client.inc");

define("WSTUNNEL_LOCALBASE", "/usr/local");
define("WSTUNNEL_ETCDIR", WSTUNNEL_LOCALBASE . "/etc/wstunnel");
define("WSTUNNEL_CHROOTDIR", "/var/tmp/wstunnel");

function wstunnel_save() {
    config_init_path("installedpackages/wstunnel/config");
    $stunnel_conf = STUNNEL_ETCDIR . "/wstunnel.conf";
    // make dir if needed
    if (!empty(config_get_path("installedpackages/wstunnel/config"))) {
        safe_mkdir(WSTUNNEL_ETCDIR);
        safe_mkdir(WSTUNNEL_CHROOTDIR . "/var/tmp/run/wstunnel");
    }
}

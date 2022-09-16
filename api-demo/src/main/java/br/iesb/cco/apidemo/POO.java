package br.iesb.cco.apidemo;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController

public class POO {
    @GetMapping("/poo")
    String hello(){
        return "Hello World!";
    }
}

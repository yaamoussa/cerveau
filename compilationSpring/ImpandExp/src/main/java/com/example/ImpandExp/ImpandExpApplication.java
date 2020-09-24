package com.example.ImpandExp;


import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.SpringApplication;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.RequestMapping;

@SpringBootApplication
public class ImpandExpApplication {

	public static void main(String[] args) {
		SpringApplication.run(ImpandExpApplication.class, args);
	}

}


@RestController
class Hello {

    @RequestMapping("/")
    String index() {
        return "Hello yaamoussa";
    }
}

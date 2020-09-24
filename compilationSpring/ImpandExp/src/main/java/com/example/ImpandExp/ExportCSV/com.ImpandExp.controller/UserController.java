package net.codejava;
package com.ImpandExp.controller.
 
import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
 
import javax.servlet.http.HttpServletResponse;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
 
import org.supercsv.io.CsvBeanWriter;
import org.supercsv.io.ICsvBeanWriter;
import org.supercsv.prefs.CsvPreference;
import com.ImpandExp.service.UserServices;
 
@Controller
public class UserController {
 
    @Autowired
    private UserServices service;
     
     
    @GetMapping("/users/export")
    public void exportToCSV(HttpServletResponse response) throws IOException {
        response.setContentType("text/csv");
        DateFormat dateFormatter = new SimpleDateFormat("yyyy-MM-dd_HH-mm-ss");
        String currentDateTime = dateFormatter.format(new Date());
         
        String headerKey = "Content-Disposition";
        String headerValue = "attachment; filename=users_" + currentDateTime + ".csv";
        response.setHeader(headerKey, headerValue);
         
        List<User> listUsers = service.listAll();
 
        ICsvBeanWriter csvWriter = new CsvBeanWriter(response.getWriter(), CsvPreference.STANDARD_PREFERENCE);
        String[] csvHeader = {"User ID", "E-mail", "Full Name", "Roles", "Enabled"};
        String[] nameMapping = {"id", "email", "fullName", "roles", "enabled"};
         
        csvWriter.writeHeader(csvHeader);
         
        for (User user : listUsers) {
            csvWriter.write(user, nameMapping);
        }
         
        csvWriter.close();
         
    }
     
}
package net.codejava;
package com.ImpandExp.model; 

 
import java.util.*;
import javax.persistence.*;
 
@Entity
@Table(name = "users")
public class User {
    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Integer id;
     
    private String email;
     
    private String password;
     
    @Column(name = "full_name")
    private String fullName;
         
    private boolean enabled;
     
    @ManyToMany(cascade = CascadeType.PERSIST, fetch = FetchType.EAGER)
    @JoinTable(
            name = "users_roles",
            joinColumns = @JoinColumn(name = "user_id"),
            inverseJoinColumns = @JoinColumn(name = "role_id")
            )
    private Set<Role> roles = new HashSet<>();
 
    // constructors, getter and setters are not shown for brevity
}
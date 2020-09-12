import { Component, OnInit } from '@angular/core';
import {AppserviceService}  from '../../services/appservice.service';

@Component({
  selector: 'app-password',
  templateUrl: './password.component.html',
  styleUrls: ['./password.component.css']
})
export class PasswordComponent implements OnInit {
  movies=[
    {title:'test' }
  ]


  constructor(private app:AppserviceService) { this.getMovies();}
  getMovies=()=>{
    this.app.getAllMovies().subscribe(
      data=>{
        this.movies=data;
      },

      error =>{
        console.error();

      })
    }
  
  ngOnInit(): void {
  
  }


}

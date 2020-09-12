import { Component } from '@angular/core';
import {AppiService} from './service/appi.service';
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'Crud';
  movies=[
    {title:'test' }
  ]


  constructor(private app:AppiService) { this.getMovies();}
  getMovies=()=>{
    this.app.getAllMovies().subscribe(
      data=>{
        this.movies=data;
      },

      error =>{
        console.error();

      })
    }
}

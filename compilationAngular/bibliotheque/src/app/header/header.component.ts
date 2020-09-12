import { Component, OnInit } from '@angular/core';
import { AuthService } from '../services/auth.service';
import { MaterialModule } from './material.module';
import {MatToolbarModule} from '@angular/material/toolbar'; 
import {MatIconModule} from '@angular/material/icon';
import {MatIconTestingModule} from '@angular/material/icon/testing';
import {MatMenuModule} from '@angular/material/menu';

import * as firebase from 'firebase';

@Component({
  selector: 'app-header',
  templateUrl: './header.component.html',
  styleUrls: ['./header.component.scss']
})
export class HeaderComponent implements OnInit {




  isAuth:boolean;

  constructor(private authService:AuthService) { }

  ngOnInit(): void {


  	firebase.auth().onAuthStateChanged(
  		(user)=>{
  			if(user){
  				this.isAuth=true;
  			}else {
  				this.isAuth=false;
  			}
  		}
  	);

  }


  onSignOut(){
  	this.authService.signOutUser();
  }

}

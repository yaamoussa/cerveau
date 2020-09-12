import { Component } from '@angular/core';
import {AppareilsPage}  from '../appareils/appareils.page';
import {Router}   from '@angular/router';



@Component({
  selector: 'app-home',
  templateUrl: 'home.page.html',
  styleUrls: ['home.page.scss'],
})
export class HomePage {

  constructor(private router:Router) {}

  onGoToAppareils() {
   this.router.navigate(['appareils']);
  }

}

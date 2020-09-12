import { Component, OnInit } from '@angular/core';
import{AppareilsPage}  from '../appareils/appareils.page';
import{SettingsPage}   from '../settings/settings.page'
import {Router}    from '@angular/router';

@Component({
  selector: 'app-tabs',
  templateUrl: './tabs.page.html',
  styleUrls: ['./tabs.page.scss'],
})
export class TabsPage implements OnInit {

  constructor(private router:Router) { }

  ngOnInit() {
  }

  onGoToAppareils() {
   this.router.navigate(['appareils']);
  }


  onGoToSettings() {
   this.router.navigate(['settings']);
  }

}

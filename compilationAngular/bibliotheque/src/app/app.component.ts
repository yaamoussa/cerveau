import { Component } from '@angular/core';
import  * as firebase from 'firebase';
import * as admin from 'firebase-admin';



@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  title = 'bibliotheque';

  constructor(){
  	const config={
  	  apiKey: 'AIzaSyCk5vfm1B1Bu0hdH6b8Tt572uNAHKaskOk',
      authDomain: 'bibliotheque-6d8c1.firebaseapp.com',
      databaseURL: 'https://bibliotheque-6d8c1.firebaseio.com',
      projectId: 'bibliotheque-6d8c1',
      storageBucket: 'bibliotheque-6d8c1.appspot.com',
      messagingSenderId: '522786263323'
  	};
  firebase.initializeApp(config);


  }
}

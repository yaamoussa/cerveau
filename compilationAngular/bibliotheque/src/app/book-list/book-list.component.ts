import { Component, OnDestroy, OnInit } from '@angular/core';
import { BooksService } from '../services/books.service';
import { Book } from '../models/book.model';
import { Subscription } from 'rxjs';
import { Router } from '@angular/router';
import  *as firebase from'firebase';

@Component({
  selector: 'app-book-list',
  templateUrl: './book-list.component.html',
  styleUrls: ['./book-list.component.scss']
})
export class BookListComponent implements OnInit,OnDestroy {


	books:Book[];
	booksSubcription:Subscription;
  name:string;
  Email:string;

  constructor(private booksService:BooksService,private router:Router) { }

  ngOnInit(): void {

  	this.booksSubcription=this.booksService.booksSubject.subscribe(
  		(fbooks:Book[])=>{
  			this.books=fbooks;
  		}

  		);
    var user = firebase.auth().currentUser;

    if (user != null) {
    user.providerData.forEach(function (profile) {

    console.log("Sign-in provider: " + profile.providerId);
    console.log("  Provider-specific UID: " + profile.uid);
    console.log("  Name: " + profile.displayName);
    console.log("  Email: " + profile.email);
    console.log("  Photo URL: " + profile.photoURL);

  });
}
  	this.booksService.emitBooks();
  }


  onNewBook(){
  	this.router.navigate(['/books','new']);
  }


  onDeliteBook(book:Book){

  	this.booksService.removeBook(book);
  }

  onViewBook(id:number){

  	this.router.navigate(['/books','view',id]);

  }

  ngOnDestroy(){

  	this.booksSubcription.unsubscribe();
  }

}

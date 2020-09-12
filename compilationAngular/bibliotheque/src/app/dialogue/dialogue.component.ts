import { Component, OnInit,Inject } from '@angular/core';
import {MAT_DIALOG_DATA} from '@angular/material/dialog';

@Component({
  selector: 'app-dialogue',
  templateUrl: './dialogue.component.html',
  styleUrls: ['./dialogue.component.scss']
})
export class DialogueComponent implements OnInit {
	let dialogRef = dialog.open(YourDialog, {
  		data: { name: 'austin' },
	});

  constructor(@Inject(MAT_DIALOG_DATA) public data: any) { }


  ngOnInit(): void {
  }

}

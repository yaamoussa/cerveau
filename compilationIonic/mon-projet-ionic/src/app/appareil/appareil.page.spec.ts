import { async, ComponentFixture, TestBed } from '@angular/core/testing';
import { IonicModule } from '@ionic/angular';

import { AppareilPage } from './appareil.page';

describe('AppareilPage', () => {
  let component: AppareilPage;
  let fixture: ComponentFixture<AppareilPage>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ AppareilPage ],
      imports: [IonicModule.forRoot()]
    }).compileComponents();

    fixture = TestBed.createComponent(AppareilPage);
    component = fixture.componentInstance;
    fixture.detectChanges();
  }));

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});

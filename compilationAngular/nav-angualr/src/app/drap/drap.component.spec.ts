import { DragDropModule } from '@angular/cdk/drag-drop';
import { async, ComponentFixture, TestBed } from '@angular/core/testing';
import { NoopAnimationsModule } from '@angular/platform-browser/animations';
import { DrapComponent } from './drap.component';

describe('DrapComponent', () => {
  let component: DrapComponent;
  let fixture: ComponentFixture<DrapComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ DrapComponent ],
      imports: [
        NoopAnimationsModule,
        DragDropModule,
      ]
    }).compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(DrapComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should compile', () => {
    expect(component).toBeTruthy();
  });
});

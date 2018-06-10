import { NgModule } from '@angular/core';
import { IonicPageModule } from 'ionic-angular';
import { HouseholdPage } from './household';

@NgModule({
  declarations: [
    HouseholdPage,
  ],
  imports: [
    IonicPageModule.forChild(HouseholdPage),
  ],
})
export class HouseholdPageModule {}

import { Component } from '@angular/core';
import { IonicPage, NavController, NavParams } from 'ionic-angular';
import { DealerPage } from '../dealer/dealer'
/**
 * Generated class for the HouseholdPage page.
 *
 * See https://ionicframework.com/docs/components/#navigation for more info on
 * Ionic pages and navigation.
 */

@IonicPage()
@Component({
  selector: 'page-household',
  templateUrl: 'household.html',
})
export class HouseholdPage {

  constructor(public navCtrl: NavController, public navParams: NavParams) {
  }

  moveOn() {
    this.navCtrl.push(DealerPage)
  }
}

import * as React from 'react';
import { Text, View, StyleSheet, Image } from 'react-native';
import IconBadge from 'react-native-icon-badge';
//import { BodyPresenceSensor } from "body-presence";
//when detecting off-wrist, want to change the colour of  icon from red to green

export default function AssetExample() {
  return (
    <View style={styles.header}>
      <View style={{flexDirection: 'row',alignItems: 'center',justifyContent: 'center'}}>
        <View style={styles.outsideCircle}>
           <View style={styles.innerCircle}>
             <Image style={styles.logo} 
           source={require('../assets/Visa-PR-e1503941848728.png')}/>
             <View style={styles.iconBadgeStyle}/>
           </View>
        </View>
      </View>
    </View>

  );
}

const styles = StyleSheet.create({
  header: {
    backgroundColor: '#fff',
    //justifyContent: 'center',
    alignItems: 'center',
    height: 80,
    paddingTop: 15,
    elevation: 2,
    position: 'relative',
    borderWidth: 2,
    borderTopColor: '#fff',
    borderLeftColor: '#fff',
    borderRightColor: '#fff',
    borderBottomColor: '#fff', //#ccc
  },

  outsideCircle: {
    marginTop: -7,
    borderRadius: 30,
    width: 60,
    height: 60,
    backgroundColor: '#666',
  },

  innerCircle:{
    borderRadius: 25,
    width: 50,
    height: 50,
    margin: 5,
    backgroundColor: 'white',
  },

  iconBadgeStyle: {
    position:'absolute',
    top:-2,
    right:-2,
    width:15,
    height:15,
    borderRadius:15,
    alignItems: 'center',
    justifyContent: 'center',
    backgroundColor: '#f00'
  },

  logo:{
    marginTop: 5,
    marginLeft: 5,
    width: 40,
    height: 40,
  },
});
